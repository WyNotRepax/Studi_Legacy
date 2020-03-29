#ifndef USTAR_H
#define USTAR_H

#include <time.h>
#include <stddef.h>

#define USTAR_BLOCKSIZE 512

#define USTAR_MAGIC_SIZE 8
#define USTAR_MAGIC_OFFSET 0x101
#define USTAR_MAGIC "ustar\00000"

#define USTAR_NAME_SIZE 100
#define USTAR_NAME_OFFSET 0

#define USTAR_MODE_SIZE 8
#define USTAR_MODE_OFFSET 100

#define USTAR_TYPEFLAG_OFFSET 156

/* Values used in typeflag field.  */
#define USTAR_REGTYPE '0'            /* regular file */
#define USTAR_AREGTYPE '\0'          /* regular file */
#define USTAR_LNKTYPE '1'            /* link */
#define USTAR_SYMTYPE '2'            /* reserved */
#define USTAR_CHRTYPE '3'            /* character special */
#define USTAR_BLKTYPE '4'            /* block special */
#define USTAR_DIRTYPE '5'            /* directory */
#define USTAR_FIFOTYPE '6'           /* FIFO special */
#define USTAR_CONTTYPE '7'           /* reserved */

#define USTAR_UNAME_SIZE 32
#define USTAR_UNAME_OFFSET 265

#define USTAR_GNAME_SIZE 32
#define USTAR_GNAME_OFFSET 297

#define USTAR_SIZE_SIZE 12
#define USTAR_SIZE_OFFSET 124

#define USTAR_MTIME_SIZE 12
#define USTAR_MTIME_OFFSET 136

int ustar_check_magic(char block[]);
void ustar_extract_magic(const char block[], char buf[]);
void ustar_extract_name(const char block[], char buf[]);
void ustar_extract_mode(const char block[], char buf[]);
void ustar_extract_typeflag(const char block[], char* c);
void ustar_extract_uname(const char block[], char buf[]);
void ustar_extract_gname(const char block[], char buf[]);
void ustar_extract_size(const char block[], char buf[]);
void ustar_extract_mtime(const char block[], char buf[]);

int USTAR_ISDIR(const char block[]);
int USTAR_ISBLK(const char block[]);
int USTAR_ISCHR(const char block[]);
int USTAR_ISLNK(const char block[]);
int USTAR_ISFIFO(const char block[]);
int USTAR_ISREG(const char block[]);

int USTAR_IRUSR(const char block[]);
int USTAR_IWUSR(const char block[]);
int USTAR_IXUSR(const char block[]);
int USTAR_IRGRP(const char block[]);
int USTAR_IWGRP(const char block[]);
int USTAR_IXGRP(const char block[]);
int USTAR_IROTH(const char block[]);
int USTAR_IWOTH(const char block[]);
int USTAR_IXOTH(const char block[]);

int USTAR_ISR(const char c);
int USTAR_ISW(const char c);
int USTAR_ISX(const char c);

void ustar_prettify_size(size_t s,char buff[], int buffsize);
time_t ustar_parse_time(const char time[]);
size_t ustar_parse_size(const char size[]);

#endif
