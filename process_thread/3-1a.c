#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include<string.h>
int main(){
    int fd[2]={0};
    if(0!=pipe(fd)){
        printf("create pipe err\n");
        return -1;
    }
    pid_t pid=fork();
    char buffer[32]={0};
    if(0==pid){
        close(fd[0]);
        printf("child process\n");
        strcpy(buffer,"child to parent");
        write(fd[1],buffer,sizeof(buffer));
    }
    else{
        printf("parent proces\n");
        close(fd[1]);
        read(fd[0],buffer,sizeof(buffer));
        printf("read data from child: %s\n",buffer);
    }

    return 0;
}