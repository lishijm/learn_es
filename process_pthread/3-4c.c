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
    alarm(1);
    return ;
}


int main(int argc,char *argv[]){
    printf("main\n");
    signal(SIGALRM,func);
    alarm(2);
    while(1){
        pause();
    }
    printf("hello,world\n");
    return 0;
}