#include <stdio.h>
#include <sys/types.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>

int i,j;
int value;

#define CMD_WRITE_DIGITAL _IOW('S',0x00,int)

int main(){

    int fd=open("/dev/digitalled",O_RDWR);
    if(fd<0){
        perror("open error:");
        return -1;
    }
    printf("open ok\n");
    while(1){
        for (i=0;i<4;i++){
            value=(i<<8)|(1<<i);
            ioctl(fd,CMD_WRITE_DIGITAL,&value);
        }
    }
    close(fd);
    
    return 0;
}