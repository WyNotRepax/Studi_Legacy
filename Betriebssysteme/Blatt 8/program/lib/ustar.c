#include "ustar.h"

#include <string.h>

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void ustar_extract_magic(const char block[], char buf[]){
    memcpy(buf,block+USTAR_MAGIC_OFFSET,USTAR_MAGIC_SIZE);
    buf[USTAR_MAGIC_SIZE] = '\000';
}

int ustar_check_magic(char block[]){
    char magicBytes[USTAR_MAGIC_SIZE+1];
    ustar_extract_magic(block,magicBytes);
    for(int i = 0; i < USTAR_MAGIC_SIZE; i++){
        if(magicBytes[i] != USTAR_MAGIC[i]){
            return 0;
        }
    }
    return 1;
}

void ustar_extract_name(const char block[], char buf[]){
    memcpy(buf,block+USTAR_NAME_OFFSET,USTAR_NAME_SIZE);
    buf[USTAR_NAME_SIZE] = '\000';
}

void ustar_extract_mode(const char block[], char buf[]){
    memcpy(buf,block+USTAR_MODE_OFFSET,USTAR_MODE_SIZE);
    buf[USTAR_MODE_SIZE] = '\000';
}

void ustar_extract_typeflag(const char block[], char* c){
    *c = block[USTAR_TYPEFLAG_OFFSET];
}

void ustar_extract_uname(const char block[], char buf[]){
    memcpy(buf,block+USTAR_UNAME_OFFSET,USTAR_UNAME_SIZE);
    buf[USTAR_UNAME_SIZE] = '\000';
}

void ustar_extract_gname(const char block[], char buf[]){
    memcpy(buf,block+USTAR_GNAME_OFFSET,USTAR_GNAME_SIZE);
    buf[USTAR_GNAME_SIZE] = '\000';
}

void ustar_extract_size(const char block[],char buf[]){
    memcpy(buf,block+USTAR_SIZE_OFFSET,USTAR_SIZE_SIZE);
    buf[USTAR_SIZE_SIZE] = '\000';
}

void ustar_extract_mtime(const char block[], char buf[]){
    memcpy(buf,block+USTAR_MTIME_OFFSET,USTAR_MTIME_SIZE);
    buf[USTAR_MTIME_SIZE] = '\000';
}

int USTAR_ISDIR(const char block[]){
    char c;
    ustar_extract_typeflag(block,&c);
    return (c == USTAR_DIRTYPE);
}

int USTAR_ISBLK(const char block[]){
    char c;
    ustar_extract_typeflag(block,&c);
    return (c == USTAR_BLKTYPE);
}

int USTAR_ISCHR(const char block[]){
    char c;
    ustar_extract_typeflag(block,&c);
    return (c == USTAR_CHRTYPE);
}

int USTAR_ISLNK(const char block[])
{
    char c;
    ustar_extract_typeflag(block,&c);
    return (c == USTAR_LNKTYPE);
}

int USTAR_ISFIFO(const char block[]){
    char c;
    ustar_extract_typeflag(block,&c);
    return (c == USTAR_FIFOTYPE);
}

int USTAR_ISREG(const char block[]){
    char c;
    ustar_extract_typeflag(block,&c);
    return (c == USTAR_REGTYPE || c == USTAR_AREGTYPE);
}

int USTAR_IRUSR(const char block[]){
    char mode[USTAR_MODE_SIZE+1];
    ustar_extract_mode(block,mode);
    return USTAR_ISR(mode[4]);
}

int USTAR_IWUSR(const char block[]){
    char mode[USTAR_MODE_SIZE+1];
    ustar_extract_mode(block,mode);
    return USTAR_ISW(mode[4]);
}

int USTAR_IXUSR(const char block[]){
    char mode[USTAR_MODE_SIZE+1];
    ustar_extract_mode(block,mode);
    return USTAR_ISX(mode[4]);
}

int USTAR_IRGRP(const char block[]){
    char mode[USTAR_MODE_SIZE+1];
    ustar_extract_mode(block,mode);
    return USTAR_ISR(mode[5]);
}

int USTAR_IWGRP(const char block[]){
    char mode[USTAR_MODE_SIZE+1];
    ustar_extract_mode(block,mode);
    return USTAR_ISW(mode[5]);
}

int USTAR_IXGRP(const char block[]){
    char mode[USTAR_MODE_SIZE+1];
    ustar_extract_mode(block,mode);
    return USTAR_ISX(mode[5]);
}

int USTAR_IROTH(const char block[]){
    char mode[USTAR_MODE_SIZE+1];
    ustar_extract_mode(block,mode);
    return USTAR_ISR(mode[6]);
}

int USTAR_IWOTH(const char block[]){
    char mode[USTAR_MODE_SIZE+1];
    ustar_extract_mode(block,mode);
    return USTAR_ISW(mode[6]);
}

int USTAR_IXOTH(const char block[]){
    char mode[USTAR_MODE_SIZE+1];
    ustar_extract_mode(block,mode);
    return USTAR_ISX(mode[6]);
}

int USTAR_ISR(const char c){
    return (c == '4' || c == '5' || c == '6' || c == '7');
}

int USTAR_ISW(const char c){
    return (c == '2' || c == '3' || c == '6' || c == '7');
}

int USTAR_ISX(const char c){
    return (c == '1' || c == '3' || c == '5' || c == '7');
}

void ustar_prettify_size(size_t s,char buff[], int buffsize){
    size_t curr_s = s;
    for(int i = buffsize - 1; i >= 0; i--){
        if(curr_s > 0){
            buff[i] = '0' + (curr_s%10);
        }
        else{
            buff[i] = ' ';
        }
        curr_s /= 10;
    }
    if(s == 0){
        buff[buffsize - 1] = '0';
    }
}


time_t ustar_parse_time(const char time[]){
    time_t ret = 0;
    unsigned long mult = 1;
    for(int i = USTAR_MTIME_SIZE; i >= 0; i--){
        if(time[i] != '\000'){
            ret += (time[i] - '0') * mult;
            mult *= 8;
        }
    }
    return ret;
}


size_t ustar_parse_size(const char size[]){
    size_t ret = 0;
    unsigned long mult = 1;
    for(int i = USTAR_SIZE_SIZE; i >= 0; i--){
        if(size[i] != '\000'){
            ret += (size[i] - '0') * mult;
            mult *= 8;
        }
    }
    return ret;
}