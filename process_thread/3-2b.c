//有名管道单工读
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<string.h>
#include <fcntl.h>
int main(){
    int fd=open("fifo",O_RDONLY);
    if(-1==fd){
        return -1;
    }
    char buffer[32]={0};
    read(fd,buffer,sizeof(buffer));
    printf("%s",buffer);
    close(fd);

    return 0;
}