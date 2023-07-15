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

int main(int argc,char *argv[]){
    int sockFd=socket(AF_INET,SOCK_STREAM,0);
    if(sockFd<0){
        perror("socket error");
        exit(1);
    }
    printf("socket ok\n");
    
    struct sockaddr_in sin;
    memset(&sin,0,sizeof(sin));
    sin.sin_family=AF_INET;
    sin.sin_port=htons(SERV_PORT);
    sin.sin_addr.s_addr=htons(INADDR_ANY);
    int ret=connect(sockFd,(struct sockaddr *)&sin,sizeof(sin));
    if(ret<0){
        perror("connect error");
        exit(1);
    }
    printf("connect ok\n");

    send(sockFd,argv[2],sizeof(argv[2]),0);
    usleep(1000000);
    puts("send filename ok");

    char buf[BUFSIZ];
    int fileFdr,fileFdw;
    if(0==strncasecmp(argv[1],PUSH,strlen(PUSH))){
        fileFdr=open(argv[2],O_RDONLY,0644);
        send(sockFd,argv[1],sizeof(argv[1]),0);
        usleep(1000000);
        puts("push start");
        while(1){
            memset(buf,0,sizeof(buf));
            ret=read(fileFdr,buf,sizeof(buf));
            if(ret==0){
                break;
            }
            else{
                send(sockFd,buf,ret,0);
            }
        }
        close(fileFdr);
    }
    else if(0==strncasecmp(argv[1],PULL,strlen(PULL))){
        fileFdw=open(argv[2],O_WRONLY|O_CREAT,0644);
        send(sockFd,argv[1],sizeof(argv[1]),0);
        while(1){
            memset(buf,0,sizeof(buf));
            ret=recv(sockFd,buf,sizeof(buf),0);
            if(ret<0){
                perror("recv error");
                continue;
            }
            if(ret==0){
                break;
            }
            write(fileFdw,buf,ret);
        }
        close(fileFdw);
    }
    close(sockFd);

    return 0;
}