#ifndef _FILERW_H_
#define _FILERW_H_

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>

int filecp(char *filename1,char *filename2);
int filesct(char *filename);

#endif