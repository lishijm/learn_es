//wait
#include <sys/types.h>
#include <sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

int main(int argc,char *argv[]){
    pid_t pid=-1;
    printf("%d\n",getpid());
    pid=fork();
    if(0==pid){
        printf("子进程执行\n");
        printf("当前进程%d 子进程%d\n",getpid(),pid);
        printf("父进程%d 当前进程%d\n",getppid(),getpid());
        sleep(5);
        exit(3);
    }
    else{
        int status=-1;
        pid_t pidtmp=wait(&status);
        printf("%d %d %d\n",WEXITSTATUS(status),pidtmp,pid);
        printf("父进程执行\n");
        printf("当前进程%d 子进程%d\n",getpid(),pid);
    }
    return 0;
}