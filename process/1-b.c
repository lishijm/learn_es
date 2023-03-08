#include<stdio.h>
#include<unistd.h>

int main(int argc,char *argv[]){
    execv("./execvtest",argv);
    printf("hello world\n");
    return 0;
}