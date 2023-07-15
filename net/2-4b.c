#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <errno.h>

#define SERV_PORT 5002
#define QUIT_STR "quit"

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
        printf("input:\n");
        memset(buf,0,sizeof(buf));
        if(fgets(buf,sizeof(buf),stdin)==NULL){
            printf("fgets error\n");
            continue;
        }
        if(strncasecmp(buf,QUIT_STR,strlen(QUIT_STR))==0){
            printf("click quit client exit\n");
            break;
        }
        send(sockFd,buf,strlen(buf),0);
    }

    return 0;
}