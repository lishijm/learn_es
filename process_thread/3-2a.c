//有名管道单工写
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<string.h>
#include <fcntl.h>

int main(){
    int ret=-1;
    ret=mkfifo("fifo",0666);
    if(ret<0&&EEXIST!=errno){
        printf("creat fifo err\n");
        return -1;
    }
    printf("make fifo success");
    int fd=open("fifo",O_WRONLY,0666);
    if(-1==fd){
        return -1;
    }
    char buffer[32]={0};
    strcpy(buffer,"fifo,fofi");
    write(fd,buffer,sizeof(buffer));
    close(fd);

    return 0;
}