#include <stdio.h>
#include <sys/types.h>
#include <sys/fcntl.h>
#include <unistd.h>
int main(){
    int fd=open("/dev/myled",O_RDWR);
    if(fd<0){
        perror("open error:");
        return -1;
    }
    else{
        printf("open ok\n");
    }

    return 0;
}