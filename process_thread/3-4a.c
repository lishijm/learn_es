//闹钟信号原型
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<string.h>
#include <fcntl.h>

int main(){
    printf("main\n");
    alarm(2);
    pause();
    printf("hello,world\n");
    return 0;
}