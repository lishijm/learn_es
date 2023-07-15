#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SERV_PORT 5050

int main(){
    int listenFd=socket(AF_INET,SOCK_STREAM,0);
    if(listenFd<0){
        perror("socket error");
        exit(0);
    }
    printf("socket ok\n");

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

    int conFd=accept(listenFd,NULL,NULL);
    if(conFd<0){
        perror("accept error");
        exit(1);
    }
    printf("accept ok\n");

    char buf[BUFSIZ];

    while(1){
        memset(buf,0,sizeof(buf));
        ret=recv(conFd,buf,sizeof(buf)-1,0);
        if(ret<0){
            perror("recv error");
            continue;
        }
        if(ret==0){
            printf("client exit\n");
            break;
        }
        printf("serv recv:%s",buf);
        send(conFd,buf,strlen(buf),0);
    }
    close(conFd);
    close(listenFd);

    return 0;
}