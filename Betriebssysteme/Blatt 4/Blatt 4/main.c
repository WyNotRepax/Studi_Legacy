/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: bsteinka
 *
 * Created on 29. Oktober 2019, 10:17
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define INPUT_BUFFERSIZE 512
#define USERNAME_BUFFERSIZE 512

/*
 * 
 */

char* USERNAME;
char* CWD;

int main(int argc, char** argv) {
    //char buffer[INPUT_BUFFERSIZE];
    //fgets(buffer, INPUT_BUFFERSIZE, stdin);
    init_prompt();
    print_prompt();
    char buffer[INPUT_BUFFERSIZE];
    while (fgets(buffer, INPUT_BUFFERSIZE, stdin) != NULL) {
        print_prompt();
        exec_cmd(buffer);
    }
    return (EXIT_SUCCESS);
}

void init_prompt() {
    USERNAME = getenv("USER");
    CWD = getenv("PWD");
}

void print_prompt() {
    printf("%s:%s ", USERNAME, CWD);
}

void exec_cmd(char* cmd) {
    pid_t pid;
    if ((pid = fork()) < 0)
        perror("fork failed\n");
    if (pid == 0) {
        execlp(cmd,"test");
    }
    printf(pid.);
}