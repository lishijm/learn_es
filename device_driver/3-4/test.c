#include <stdio.h>
#include <sys/types.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
#include "ioctl.h"

char cmd;
char *filename;

int main(int argc,char *argv[]){
    filename=argv[1];
    int fd=open(filename,O_RDWR);
    if(fd<0){
        perror("open error:");
        return -1;
    }

while(1){
    cmd=0;
    scanf("%c",&cmd);
    if(cmd=='1'){
        ioctl(fd,IOCTL_CMD_LED_ON);
    }
    else if(cmd=='0'){
        ioctl(fd,IOCTL_CMD_LED_OFF);
    }
}
    close(fd);
    
    return 0;
}