#include<stdio.h>
#include<unistd.h>

int main(int argc,char *argv[],char *envp[]){
    execvpe("PATH",argv,envp);
    printf("hello world\n");
    return 0;
}