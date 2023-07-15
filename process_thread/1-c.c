#include<stdio.h>
#include<unistd.h>

int main(int argc,char *argv[]){
    char *str[]={"ls","-l"};
    execvp("ls",str);
    printf("hello world\n");
    return 0;
}