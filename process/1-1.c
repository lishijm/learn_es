#include <sys/types.h>
#include<stdio.h>
#include <unistd.h>

int main(int argc,char *argv[]){
    pid_t pid=-1;
    printf("%d\n",getpid());
    pid=fork();
    if(0==pid){
        printf("%d %d\n",getpid(),pid);
        printf("p%d %d\n",getppid(),getpid());
    }
    else{
        printf("x%d %d\n",getpid(),pid);
    }
    return 0;
}