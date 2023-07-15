#include <stdio.h>
#include <sys/types.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include <string.h>

char buf[64];

int main(){
    int fd=open("/dev/demo",O_RDWR);
    if(fd<0){
        perror("open error:");
        return -1;
    }
    printf("open ok\n");
    
    scanf("%s",buf);
    printf("after scanf,buf = %s\n",buf);
    
    write(fd,buf,strlen(buf));
    memset(buf, 0, sizeof(buf));
    printf("after memset,buf= %s\n",buf);
    
    read(fd,buf,sizeof(buf));
    printf("after read,buf = %s\n",buf);
    
    close(fd);
    
    return 0;
}