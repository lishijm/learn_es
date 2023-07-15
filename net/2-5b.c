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
#define SERV_IP "192.168.8.163"

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
    sin.sin_addr.s_addr=inet_addr(SERV_IP);
    int ret=connect(sockFd,(struct sockaddr *)&sin,sizeof(sin));
    if(ret<0){
        perror("connect error");
        exit(1);
    }
    printf("connect ok\n");
    
    char buf[BUFSIZ];
    int fileFd,rn;
    fileFd=open(argv[1],O_RDONLY,0644);

    while(1){
        memset(buf,0,sizeof(buf));
        rn=read(fileFd,buf,sizeof(buf));
        if(rn==0){
            break;
        }
        else{
            send(sockFd,buf,rn,0);
        }
    }
    close(fileFd);
    close(sockFd);

    return 0;
}