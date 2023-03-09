//waitpid
#include <sys/types.h>
#include <sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

int main(int argc,char *argv[]){
    pid_t pid=-1;
    pid=fork();
    if(0==pid){
        printf("子进程执行\n");
        printf("%d\n",getpid());
        printf("当前进程%d 子进程%d\n",getpid(),pid);
        printf("父进程%d 当前进程%d\n",getppid(),getpid());
        sleep(5);
        exit(1);
    }
    else{
        int status=-1;
        pid_t pidtmp=-1;
        while(0==(pidtmp=waitpid(pid,&status,WNOHANG))){
            printf("no exit status\n");
            sleep(1);
        }
        printf("%d %d %d\n",WEXITSTATUS(status),pidtmp,pid);
        printf("父进程执行\n");
        printf("%d\n",getpid());
        printf("当前进程%d 子进程%d\n",getpid(),pid);
        sleep(10);
    }
    return 0;
}