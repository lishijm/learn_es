#include<stdio.h>
#include<unistd.h>

int main(int argc,char *argv[],char envp[]){
    char *str[]={"PATH=/mnt/hgfs:$PATH",NULL};
    execle("/usr/bin/env","env",NULL,str);
    printf("hello world\n");
    return 0;
}