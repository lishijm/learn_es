//用ls -a替换hello输出
#include<stdio.h>
#include<unistd.h>

int main(){
    execlp("ls","ls","-a",NULL);
    printf("hello\n");
    return 0;
}