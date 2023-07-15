#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

#define BEEPOFF 0
#define BEEPON  1

int main(int argc,char *argv[]){
    int fd,retvalue;
    char *filename;
    unsigned char databuf[1];

    if(argc !=3){
        printf("error usage!\r\n");
        goto error;
    }
    filename =argv[1];
    fd=open(filename,O_RDWR);
    if(fd<0){
        printf("file %s open failed\r\n",argv[1]);
        goto error;
    }
    databuf[0]=atoi(argv[2]);
    retvalue=write(fd,databuf,sizeof(databuf));
    if(retvalue<0){
        printf("beep control error\r\n");
        goto close_fd;
    }
    retvalue=close(fd);
    if(retvalue<0){
        printf("file %s close failed\r\n",argv[1]);
        goto error;
    }

    return 0;

close_fd:
    close(fd);
error:
    return -1;

}