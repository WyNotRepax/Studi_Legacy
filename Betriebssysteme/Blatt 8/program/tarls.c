#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include "ustar.h"
#include <time.h>

#define DATE_BUFSIZE 32
#define SIZE_BUFSIZE 8

void writeString(int fd, const char s[]);
void printUsage(const char name[]);
void printErr();
int checkFDType(int fd);
int checkFileType(int fd);
void readAllBlocks(int fd);
void formatModeBits(char modeBits[], const char block[]);
char* formatDate(__time_t t);


int main(int argc, char const *argv[])
{
    if(argc <= 1 || argc > 2){
        printUsage(argv[0]);
        return EXIT_FAILURE;
    }
    int input_fileno = open(argv[1],O_RDONLY);
    if(input_fileno < 0){
        printErr();
        return EXIT_FAILURE;
    }
    if(!checkFDType(input_fileno)){
        printErr();
        return EXIT_FAILURE;
    }
    if(!checkFileType(input_fileno)){
        printErr();
        return EXIT_FAILURE;
    }
    readAllBlocks(input_fileno);
    return EXIT_SUCCESS;
}

void writeString(int fd, const char s[]){
    write(fd,s,sizeof(char)*strlen(s));
}

void printUsage(const char name[]){
    writeString(STDERR_FILENO,"Usage:\n");
    writeString(STDERR_FILENO,name);
    writeString(STDERR_FILENO," <filename>\n");
}

void printErr(){
    if(errno == ENOENT){
        writeString(STDERR_FILENO,"File does not exist!\n");
    }
    else if(errno == EISDIR){
        writeString(STDERR_FILENO,"File is not a Normal File!\n");
    }
    else if(errno == EMEDIUMTYPE){
        writeString(STDERR_FILENO,"File is not of the ustar format!\n");
    }
    else{
        writeString(STDERR_FILENO, "File could not be opened!\n");
    }
}

int checkFDType(int fd){
    errno = 0;
    struct stat stats;
    if(fstat(fd,&stats) != 0){
        return 0;
    }
    if(S_ISREG(stats.st_mode)){
        return 1;
    }
    errno = EISDIR;
    return 0;
}

int checkFileType(int fd){
    char firstBlock[USTAR_BLOCKSIZE];
    lseek(fd,0,SEEK_SET);
    read(fd,firstBlock,USTAR_BLOCKSIZE);
    if(ustar_check_magic(firstBlock)){
        return 1;
    }
    errno = EMEDIUMTYPE;
    return 0;
}

void readAllBlocks(int fd){
    char block[USTAR_BLOCKSIZE];
    lseek(fd,0,SEEK_SET);
    while(read(fd,block,USTAR_BLOCKSIZE)>0){
        if(ustar_check_magic(block)){
            char modeBits[11];
            formatModeBits(modeBits, block);
            writeString(STDOUT_FILENO,modeBits);

            writeString(STDOUT_FILENO," ");

            char uname[USTAR_UNAME_SIZE+1];
            ustar_extract_uname(block,uname);
            writeString(STDOUT_FILENO,uname);

            writeString(STDOUT_FILENO,"/");

            char gname[USTAR_GNAME_SIZE+1];
            ustar_extract_gname(block,gname);
            writeString(STDOUT_FILENO,gname);

            writeString(STDOUT_FILENO," ");

            char sizeRaw[USTAR_SIZE_SIZE+1];
            ustar_extract_size(block,sizeRaw);
            size_t s = ustar_parse_size(sizeRaw);
            char size[SIZE_BUFSIZE];
            ustar_prettify_size(s,size,SIZE_BUFSIZE);
            writeString(STDOUT_FILENO,size);

            writeString(STDOUT_FILENO," ");

            char mtime[USTAR_MTIME_SIZE +1];
            ustar_extract_mtime(block,mtime);
            time_t t;
            t = ustar_parse_time(mtime);
            char timeStr[DATE_BUFSIZE];
            strftime(timeStr,DATE_BUFSIZE,"%Y-%m-%d %H:%M",localtime(&t));
            writeString(STDOUT_FILENO,timeStr);

            writeString(STDOUT_FILENO," ");

            char name[USTAR_NAME_SIZE+1];
            ustar_extract_name(block,name);
            writeString(STDOUT_FILENO,name);
            writeString(STDOUT_FILENO,"\n");

            if(s % USTAR_BLOCKSIZE != 0){
                s -= s%USTAR_BLOCKSIZE;
                s += USTAR_BLOCKSIZE;
            }
            lseek(fd,s,SEEK_CUR);
        }
        else{exit(1);}
    }
    
}

void formatModeBits(char modeBits[], const char block[]){
    if(USTAR_ISDIR(block)){
        modeBits[0] = 'd';
    }
    else if(USTAR_ISBLK(block)){
        modeBits[0] = 'b';
    }
    else if(USTAR_ISCHR(block)){
        modeBits[0] = 'c';
    }
    else if (USTAR_ISLNK(block)){
        modeBits[0] = 'l';
    }
    else if (USTAR_ISFIFO(block)){
        modeBits[0] = 'p';
    }
    else if(USTAR_ISREG(block)){
        modeBits[0] = '-';
    }
    else{
        modeBits[0] = '?';
    }

    if(USTAR_IRUSR(block)){
        modeBits[1] = 'r';
    }
    else{
        modeBits[1] = '-';
    }

    if(USTAR_IWUSR(block)){
        modeBits[2] = 'w';
    }
    else{
        modeBits[2] = '-';
    }

    if(USTAR_IXUSR(block)){
        modeBits[3] = 'x';
    }
    else{
        modeBits[3] = '-';
    }

    if(USTAR_IRGRP(block)){
        modeBits[4] = 'r';
    }
    else{
        modeBits[4] = '-';
    }

    if(USTAR_IWGRP(block)){
        modeBits[5] = 'w';
    }
    else{
        modeBits[5] = '-';
    }

    if(USTAR_IXGRP(block)){
        modeBits[6] = 'x';
    }
    else{
        modeBits[6] = '-';
    }

    if(USTAR_IROTH(block)){
        modeBits[7] = 'r';
    }
    else{
        modeBits[7] = '-';
    }

    if(USTAR_IWOTH(block)){
        modeBits[8] = 'w';
    }
    else{
        modeBits[8] = '-';
    }

    if(USTAR_IXOTH(block)){
        modeBits[9] = 'x';
    }
    else{
        modeBits[9] = '-';
    }
    modeBits[10] = '\000';
}
