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
        close(fd[1]);
        printf("child process\n");
        read(fd[0],buffer,sizeof(buffer));
        printf("read data from parent: %s\n",buffer);
    }
    else{
        close(fd[0]);
        printf("parent proces\n");
        strcpy(buffer,"parent to child");
        write(fd[1],buffer,sizeof(buffer));
        printf("over\n");
    }

    return 0;
}