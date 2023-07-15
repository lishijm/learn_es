//kill发出信号
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<string.h>
#include <fcntl.h>
#include<signal.h>

int main(int argc,char *argv[]){
    if(2!=argc||NULL==argv[1]){
        printf("参数缺失\n");
        return -1;
    }
    int pid=atoi(argv[1]);
    kill(pid,SIGUSR1);
    return 0;
}