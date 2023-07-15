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

    char buf[BUFSIZ];

    while(1){
        printf("input:");
        memset(buf,0,sizeof(buf));
        if(fgets(buf,sizeof(buf),stdin)==NULL){
            printf("fgets error\n");
            continue;
        }
        send(sockFd,buf,strlen(buf),0);
        memset(buf,0,sizeof(buf));
        ret=recv(sockFd,buf,sizeof(buf)-1,0);
        printf("serv recv:%s",buf);
        
    }

    return 0;
}