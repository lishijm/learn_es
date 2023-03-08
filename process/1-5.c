#include<stdio.h>
#include<unistd.h>

int main(int argc,char *argv[],char *envp[]){
    char *arr1[]={"aaa","bbb",NULL};

    execvep("./a.out",arr1);
    return 0;
}