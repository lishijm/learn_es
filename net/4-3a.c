#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SERV_PORT 5050
#define PUSH "push"
#define PULL "pull"

void client(int conFd){
    char filename[20];
    memset(filename,0,sizeof(filename));
    recv(conFd,filename,sizeof(filename),0);
    
    int fileFdr,fileFdw,ret;
    char option[20];
    memset(option,0,sizeof(option));
    recv(conFd,option,sizeof(option),0);

    char buf[BUFSIZ];
    if(0==strncasecmp(option,PUSH,strlen(PUSH))){
        fileFdw=open(filename,O_WRONLY|O_CREAT,0644);
        while(1){
            memset(buf,0,sizeof(buf));
            ret=recv(conFd,buf,sizeof(buf),0);
            if(ret<0){
                perror("recv error");
                continue;
            }
            if(ret==0){
                printf("client exit\n");
                break;
            }
            write(fileFdw,buf,ret);
        }
        close(fileFdw);
    }
    else if(0==strncasecmp(option,PULL,strlen(PULL))){
        fileFdr=open(filename,O_RDONLY,0644);
        while(1){
            memset(buf,0,sizeof(buf));
            ret=read(fileFdr,buf,sizeof(buf));
            if(ret==0){
                break;
            }
            else{
                send(conFd,buf,ret,0);
            }
        }
        close(fileFdr);
    }
}

int main(){
    int listenFd=socket(AF_INET,SOCK_STREAM,0);
    if(listenFd<0){
        perror("socket error");
        exit(1);
    }
    printf("socket ok\n");
    
    int on=1;
    setsockopt(listenFd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on));

    struct sockaddr_in sin;
    memset(&sin,0,sizeof(sin));
    sin.sin_family=AF_INET;
    sin.sin_port=htons(SERV_PORT);
    sin.sin_addr.s_addr=htons(INADDR_ANY);
    int ret=bind(listenFd,(struct sockaddr *)&sin,sizeof(sin));
    if(ret<0){
        perror("bind error");
        exit(1);
    }
    printf("bind ok\n");

    ret=listen(listenFd,5);
    if(ret<0){
        perror("listen error");
        exit(1);
    }
    printf("listen ok\n");
    int conFd;
    pid_t pid;
    while(1){
        conFd=accept(listenFd,NULL,NULL);
        if(conFd<0){
            perror("accept error");
            exit(1);
        }
        printf("accept ok\n");
        pid=fork();
        if(pid<0){
            perror("fork error");
            continue;
        }
        else if(0==pid){
            close(listenFd);
            client(conFd);
            close(conFd);
            exit(0);
        }
        else{
            close(conFd);
        }
    }
    
    return 0;
}