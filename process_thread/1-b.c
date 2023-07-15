#include<stdio.h>
#include<unistd.h>

int main(int argc,char *argv[]){
    char *str1[]={"a1","b2",NULL};
    execv("./execvtest",str1);
    printf("hello world\n");
    return 0;
}