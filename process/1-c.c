#include<stdio.h>
#include<unistd.h>

int main(int argc,char *argv[]){
    execvp("ls",argv);
    printf("hello world\n");
    return 0;
}