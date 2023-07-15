#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include <sys/stat.h>

int main(){
    pid_t pid=-1;
    pid=fork();
    if(-1==pid){
        printf("error");
        return -1;
    }
    if(pid>0){
        printf("%d %d\n",getpid(),pid);
        exit(0);
    }
    sleep(5);
    printf("parent process has exit\n");
    pid_t spid;
    spid=setsid();
    printf("%d %d %d %d\r\n",getppid(),getpid(),spid,pid);
    chdir("/");
    umask(0);
    int i;
    int num=getdtablesize();
    for(i=0;i<num;i++){
        close(i);
    }
    return 0;
}