#include<stdio.h>
#include<unistd.h>

int main(int argc,char *argv[]){
    execl("./execltest",argv[1],argv[2],NULL);
    printf("hello world\n");
    return 0;
}