//闹钟信号更改为func
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<string.h>
#include <fcntl.h>
#include<signal.h>

void func(){
    printf("signanl change alarm\n");
    return ;
}


int main(int argc,char *argv[]){
    printf("main\n");
    signal(SIGALRM,func);
    alarm(5);
    pause();
    printf("hello,world\n");
    return 0;
}