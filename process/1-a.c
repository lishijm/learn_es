#include<stdio.h>
#include<unistd.h>

int main(int argc,char *argv[],char envp[]){
    execle("/usr/bin/env","env",NULL,envp);
    printf("hello world\n");
    return 0;
}