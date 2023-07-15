#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>

#define SERV_PORT 5052

int main(){
    //创建套接字
    int sockFd=socket(AF_INET,SOCK_DGRAM,0);
    if(sockFd<0){
        perror("socket error");
        exit(1);
    }
    printf("socket ok\n");
    //绑定IP，PORT
    struct sockaddr_in sin;
    memset(&sin,0,sizeof(sin));
    sin.sin_family=AF_INET;
    sin.sin_port=htons(SERV_PORT);
    sin.sin_addr.s_addr=htons(INADDR_ANY);
    int ret=bind(sockFd,(struct sockaddr *)&sin,sizeof(sin));
    if(ret<0){
        perror("bind error");
        exit(1);
    }
    printf("bind ok\n");

    char buf[BUFSIZ];
    char buf1[BUFSIZ+20];
    struct sockaddr_in cin;
    socklen_t len;

    while(1){
        //收消息
        do{
            memset(buf,0,sizeof(buf));
            memset(&cin,0,sizeof(cin));
            len=sizeof(cin);
            ret=recvfrom(sockFd,buf,sizeof(buf)-1,0,(struct sockaddr *)&cin,&len);
        }while(ret<0&&errno==EINTR);

        if(ret<0){
            perror("recvfrom error");
            continue;
        }
        printf("recvfrom:(%s:%d):%s",inet_ntoa(cin.sin_addr),ntohs(cin.sin_port),buf);
        //发消息
        memset(buf1,0,sizeof(buf1));
        sprintf(buf1,"server reponse:%s",buf);
        sendto(sockFd,buf1,strlen(buf1),0,(struct sockaddr *)&cin,len);
    }
    close(sockFd);
    return 0;
}