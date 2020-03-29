#include <unistd.h>    // getpid(), getcwd()
#include <sys/types.h> // type definitions, e.g., pid_t
#include <sys/wait.h>  // wait()
#include <signal.h>    // signal name constants and kill()
#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <cstdlib>
#include <sstream>

using namespace std;

int startProg(char *prog, char **argv);
int setCommand(char **argv);
int cdCommand(char **argv);
void replaceVars(char *inStr);
int executeCommand(char *command);
int executePipe(char *command1, char *command2);
char **extractArguments(char *command);

int main()
{
    while (true)
    {
        // Promt Anzeigen
        cout << getenv("USER") << ":" << getenv("PWD") << ": " << flush;
        // Buffer Erzeugen
        char command[128];
        // Befehl Einlesen
        cin.getline(command, 128);
        replaceVars(command);
        char *firstCommand = strtok(command, "|");
        char *secondCommand = strtok(NULL, "|");
        if (secondCommand == NULL)
        {
            if (executeCommand(command) == 1)
            {
                return EXIT_SUCCESS;
            }
        }
        else
        {
            char *thirdCommand = strtok(NULL, "|");
            if (thirdCommand == NULL)
            {
                executePipe(command, secondCommand);
            }
            else
            {
                perror("Nur eine Pipe pro eingabe!");
            }
        }
    }
}

int executePipe(char *command1, char *command2)
{
    char **argv1 = extractArguments(command1);
    char **argv2 = extractArguments(command2);
    command1 = argv1[0];
    command2 = argv2[0];
    int fd[2];
    if (pipe(fd) != 0)
    {
        perror("Pipe Error!");
        return -1;
    }
    pid_t child1 = fork();
    pid_t child2;
    if (child1 < 0)
    {
        perror("Fork Error!");
        return -1;
    }
    else if (child1 == 0)
    {
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        execvp(command1, argv1);
        perror(command2);
        exit(1);
        return -1;
    }
    else
    {
        child2 = fork();
        if (child2 < 0)
        {
            perror("Fork Error!");
            return -1;
        }
        else if (child2 == 0)
        {
            close(fd[1]);
            dup2(fd[0], STDIN_FILENO);
            execvp(command2, argv2);
            perror(command2);
            exit(1);
            return -1;
        }
        else
        {
            close(fd[0]);
            close(fd[1]);
            if (waitpid(child2, 0, 0) < 0)
            {
                perror("Interner Fehler.");
                return -1;
            }
            kill(child1,SIGKILL);
            if (waitpid(child1, 0, 0) < 0)
            {
                perror("Interner Fehler.");
                return -1;
            }
        }
    }

    return 0;
}

int executeCommand(char *command)
{
    // Umgebungprogsvariablen aufloesen
    replaceVars(command);

    // Argumente Extrahieren
    char **argv = extractArguments(command);

    // ueberpruefung auf exit, dann Programm beenden
    if (strcmp(command, "exit") == 0)
    {
        return 1;
    }
    else if (strcmp(command, "cd") == 0)
    {
        cdCommand(argv);
    }
    else if (strcmp(command, "set") == 0)
    {
        setCommand(argv);
    }
    else
    {
        startProg(command, argv);
    }
    return 0;
}

char **extractArguments(char *command)
{
    vector<char *> args;

    // Ersten Teilstring extrahieren
    char *tmp = strtok(command, " ");

    // Teilstrings zu Vector hinzufuegen
    while (tmp != NULL)
    {
        args.push_back(tmp);
        tmp = strtok(NULL, " ");
    }

    // Inhalt des Vectors in Array Kopieren + NULL an letzte stelle
    char **argv = new char *[args.size() + 1];
    for (int k = 0; k < args.size(); k++)
        argv[k] = args[k];
    argv[args.size()] = NULL;
    return argv;
}

void replaceVars(char *inStr)
{
    stringstream replacer;
    char *curr = inStr;
    while (*curr != '\0')
    {
        if (*curr == '$')
        {
            stringstream check;
            curr++;
            while (*curr != '\0')
            {
                check << *curr;
                char *val = getenv(check.str().c_str());
                if (val != NULL)
                {
                    replacer << val;
                    break;
                }
                curr++;
            }
        }
        else
        {
            replacer << *curr;
        }
        curr++;
    }
    strcpy(inStr, replacer.str().c_str());
}

int cdCommand(char **argv)
{
    if (argv[1] == NULL)
    {
        chdir("/");
    }
    else
    {
        chdir(argv[1]);
    }

    char cwdBuff[128];
    if (getcwd(cwdBuff, 128) == NULL)
    {
        perror("Konnte CWD nicht lesen.");
        return -1;
    }
    setenv("PWD", cwdBuff, 128);
    return 1;
}

int setCommand(char **argv)
{
    if (argv[1] != NULL && argv[2] != NULL)
    {
        setenv(argv[1], argv[2], 128);
    }
}

int startProg(char *prog, char **argv)
{
    pid_t kidpid = fork();
    switch (kidpid)
    {
    case -1:
        perror("Fork Fehlgeschlagen!");
        break;
    case 0:
        // Im Kindprozess
        execvp(prog, argv);
        // Sollte nicht aufgerufen werden
        perror("Befehl nicht gefunden:");
        exit(1);
        return -1;
        break;
    default:
        // Auf Kindprozess warten
        if (waitpid(kidpid, 0, 0) < 0)
        {
            perror("Interner Fehler.");
            return -1;
        }
        break;
    }
    return 1;
}
