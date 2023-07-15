//验证文件IO无缓存
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include<unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc,char *argv[]){
	char teststr[1030];
	int i;
	for(i=0;i<1030;i++){
		teststr[i]='a';
	}
	int fd;
	fd=open(argv[1],O_RDWR|O_CREAT);
	write(fd,teststr,sizeof(teststr));
    _exit(-1);
}