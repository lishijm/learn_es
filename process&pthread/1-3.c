//僵尸进程
#include <sys/types.h>
#include<stdio.h>
#include <unistd.h>

int main(int argc,char *argv[]){
    pid_t pid=-1;
    printf("%d\n",getpid());
    pid=fork();
    if(0==pid){
        printf("子进程执行\n");
        printf("当前进程%d 子进程%d\n",getpid(),pid);
        printf("父进程%d 当前进程%d\n",getppid(),getpid());
    }
    else{
        printf("父进程执行\n");
        printf("当前进程%d 子进程%d\n",getpid(),pid);
        while(1);
    }
    return 0;
}