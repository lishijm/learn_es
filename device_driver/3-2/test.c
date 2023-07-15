#include <stdio.h>
#include <sys/types.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
#include "ioctl.h"

char buf[64];

int main(){
    int fd=open("/dev/demo",O_RDWR);
    if(fd<0){
        perror("open error:");
        return -1;
    }
    printf("open ok\n");
#if 0
    scanf("%s",buf);
    printf("after scanf,buf = %s\n",buf);
    
    write(fd,buf,strlen(buf));
    memset(buf, 0, sizeof(buf));
    printf("after memset,buf= %s\n",buf);
    
    read(fd,buf,sizeof(buf));
    printf("after read,buf = %s\n",buf);
#endif
while(1){
    memset(buf, 0, sizeof(buf));
    scanf("%s",buf);
    if(buf[0]=='1'){
        ioctl(fd,IOCTL_CMD_LED1_ON);
    }
    else if(buf[0]=='0'){
        ioctl(fd,IOCTL_CMD_LED1_OFF);
    }
}
    close(fd);
    
    return 0;
}