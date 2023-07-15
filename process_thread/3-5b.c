//pause接收信号
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<string.h>
#include <fcntl.h>
#include<signal.h>

void func1(int signo){
    if(SIGUSR1==signo){
        printf("user1 signal\n");
    }
    else{
        printf("other");
    }
}

void func2(int signo){
    if(SIGUSR2==signo){
        printf("user2 signal\n");
    }
    else{
        printf("other");
    }
}

int main(){
    printf("pid=%d\n",getpid());
    signal(SIGUSR1,func1);
    signal(SIGUSR2,func2);
    while(1){
        pause();
    }

    return 0;
}