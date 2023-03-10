//有名管道半双工b
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
    ret=mkfifo("fifoa",0666);
    if(ret<0&&EEXIST!=errno){
        printf("creat fifoa err\n");
        return -1;
    }
    printf("make fifoa success\n");
    ret=mkfifo("fifob",0666);
    if(ret<0&&EEXIST!=errno){
        printf("creat fifob err\n");
        return -1;
    }
    printf("make fifob success\n");
    int fdra=open("fifoa",O_RDONLY,0666); 
    if(-1==fdra){
        return -1;
    }
    char buffer[32]={0};
    int fdwb=open("fifob",O_WRONLY,0666);
    if(-1==fdwb){
        return -1;
    }
    while(1){
        memset(buffer,0,sizeof(buffer));
        read(fdra,buffer,sizeof(buffer));
        printf("%s",buffer);
        memset(buffer,0,sizeof(buffer));
        fgets(buffer,sizeof(buffer),stdin);
        write(fdwb,buffer,sizeof(buffer));
    }
    
    close(fdwb);
    close(fdra);

    return 0;
}