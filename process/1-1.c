#include <sys/types.h>
#include<stdio.h>
#include <unistd.h>

int main(int argc,char *argv[]){
    pid_t pid=1;
    printf("%d\n",fork());
    return 0;
}