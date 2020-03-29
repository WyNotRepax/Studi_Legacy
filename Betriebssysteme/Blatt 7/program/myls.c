#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

#define DIR_BUFF_SIZE 128


int isA = 0;
int isG = 0;
int isL = 0;
int isO = 0;
char dir[DIR_BUFF_SIZE];
int isLocalDir = 1;
DIR* dirptr = NULL;

int checkOptions(int argc, char** argv);
int resolveOption(char option);
int checkDir(int argc, char** argv);
int listLong();
int listShort();
void formatModeBits(char modeBits[], __mode_t st_mode);
char* formatDate(__time_t t);

int main(int argc, char** argv){
    if(checkOptions(argc,argv) != 0){
        fprintf(stderr,
        "Usage %s [options] [inputdirectory]\n\n"
        "Options:\n"
        "-a\n"
        "-g\n"
        "-l\n"
        "-o\n",
        argv[0]
        );
        return EXIT_FAILURE;
    }

    if(checkDir(argc,argv)!=0){
        fprintf(stderr,
        "Maximal 1 Directory Erlaubt!\n"
        );
        return EXIT_FAILURE;
    }
    if(isLocalDir){
        strcpy(dir,".");
    }

    dirptr = opendir(dir);
    if(dirptr == NULL){
        switch (errno)
        {
        case ENOTDIR:
            fprintf(stderr,
                "%s is not a directory!\n",
                dir
                );
            break;
        case ENOENT:
            fprintf(stderr,
                "%s does not exist!\n",
                dir
                );
            break;
        default:
            perror("Error opening directory!");
            break;
        }
        return EXIT_FAILURE;
    }
    if(isL || isG || isO){
        listLong();
    }
    else{
        listShort();
    }
    return EXIT_SUCCESS;
}

int checkOptions(int argc, char** argv){
    for(int i = 1; i < argc; i++){
        char* curr = argv[i];
        if(curr[0] == '-'){
            int l = strlen(curr);
            for(int n = 1; n < l; n++){
                if(resolveOption(curr[n]) != 0){
                    return 1;
                }
            }
        }
    }
    return 0;
}

int resolveOption(char option){
    switch(option){
        case 'a':
            isA = 1;
            break;
        case 'g':
            isG = 1;
            break;
        case 'l':
            isL = 1;
            break;
        case 'o':
            isO = 1;
            break;
        default:
            return 1;
    }
    return 0;
}

int checkDir(int argc, char** argv){
    for(int i = 1; i < argc; i++){
        char* curr = argv[i];
        if(curr[0] != '-'){
            if(isLocalDir == 1){
                strcpy(dir,curr);
                isLocalDir = 0;
            }
            else{
                return 1;
            }
        }
    }
    return 0;
}

int listLong(){
    char* opBuffer = NULL;
    size_t opBufferSize = 0;    
    FILE* opStream = open_memstream(&opBuffer,&opBufferSize);
    
    long int total = 0;
    errno = 0;
    while(1){
        struct dirent* curr = readdir(dirptr);
        if(curr == NULL){
            break;
        }
        if(isA || curr->d_name[0] != '.'){
            char* path = malloc(sizeof(char)*(strlen(dir)+1+strlen(curr->d_name)));
            strcpy(path,dir);
            strcat(path,"/");
            strcat(path,curr->d_name);
            struct stat* currstat = malloc(sizeof(struct stat));
            lstat(path,currstat);
            free(path);
            char modeBits[10];
            formatModeBits(modeBits,currstat->st_mode);
            fprintf(opStream,"%s ", modeBits);
            fprintf(opStream,"%lu ",currstat->st_nlink);
            if(!isG){
                fprintf(opStream,"%s ",getpwuid(currstat->st_uid)->pw_name);
            }
            if(!isO){
                fprintf(opStream,"%s ",getgrgid(currstat->st_gid)->gr_name);
            }
            fprintf(opStream,"%5ld ",currstat->st_size);
            fprintf(opStream,"%s ",formatDate(currstat->st_mtime));
            fprintf(opStream,"%s\n",curr->d_name);
            if(S_ISDIR(currstat->st_mode)== 0){
                total += ((currstat->st_blocks) + 1)/2;
            }
            free(currstat);
        }
    }
    fclose(opStream);
    printf("Insgesamt %ld\n",total);
    printf("%s",opBuffer);
    if(errno != 0){
        perror("Error reading file");
        return 1;
    }
    return 0;
}

int listShort(){
    errno = 0;
    while(1){
        struct dirent* curr = readdir(dirptr);
        if(curr == NULL){
            break;
        }
        if(isA || curr->d_name[0] != '.'){
            printf("%s  ",curr->d_name);
        }
    }
    printf("\n");
    if(errno != 0){
        perror("Error reading file");
        return 1;
    }
    return 0;
}

void formatModeBits(char modeBits[], __mode_t st_mode){
    if(S_ISDIR(st_mode )!= 0){
        modeBits[0] = 'd';
    }
    else if(S_ISBLK(st_mode)!= 0){
        modeBits[0] = 'b';
    }
    else if(S_ISCHR(st_mode)!=0){
        modeBits[0] = 'c';
    }
    else if (S_ISLNK(st_mode)!=0){
        modeBits[0] = 'l';
    }
    else if (S_ISFIFO(st_mode)!=0){
        modeBits[0] = 'p';
    }
    else if(S_ISREG(st_mode)!=0){
        modeBits[0] = '-';
    }
    else if(S_ISSOCK(st_mode)!=0){
        modeBits[0] = 's';
    }
    else{
        modeBits[0] = '?';
    }

    if((S_IRUSR & st_mode) == S_IRUSR){
        modeBits[1] = 'r';
    }
    else{
        modeBits[1] = '-';
    }

    if((S_IWUSR & st_mode) == S_IWUSR){
        modeBits[2] = 'w';
    }
    else{
        modeBits[2] = '-';
    }

    if((S_IXUSR & st_mode) == S_IXUSR){
        modeBits[3] = 'x';
    }
    else{
        modeBits[3] = '-';
    }

    if((S_IRGRP & st_mode) == S_IRGRP){
        modeBits[4] = 'r';
    }
    else{
        modeBits[4] = '-';
    }

    if((S_IWGRP & st_mode) == S_IWGRP){
        modeBits[5] = 'w';
    }
    else{
        modeBits[5] = '-';
    }

    if((S_IXGRP & st_mode) == S_IXGRP){
        modeBits[6] = 'x';
    }
    else{
        modeBits[6] = '-';
    }

    if((S_IROTH & st_mode) == S_IROTH){
        modeBits[7] = 'r';
    }
    else{
        modeBits[7] = '-';
    }

    if((S_IWOTH & st_mode) == S_IWOTH){
        modeBits[8] = 'w';
    }
    else{
        modeBits[8] = '-';
    }

    if((S_IXOTH & st_mode) == S_IXOTH){
        modeBits[9] = 'x';
    }
    else{
        modeBits[9] = '-';
    }
}

char* formatDate(__time_t t){
    static long int SIXMONTHS = 60*60*24*182;
    char* buf = malloc(sizeof(char)*36);
    if(difftime(time(NULL),t)>SIXMONTHS){
        strftime(buf,36,"%b %d %H:%M %Y",localtime(&t));
    }
    else{
        strftime(buf,36,"%b %d %H:%M",localtime(&t));
    }
    return buf;
}