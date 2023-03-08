#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>

int main(int argc,char *argv[]){
    printf("%d",open(argv[1],O_RDONLY));
    return 0;
}