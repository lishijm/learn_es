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
#define SERV_IP "192.168.8.226"
#define CLNT_PORT 5053
#define CLNT_IP "192.168.8.226"

int main(){
    int listenFd=socket(AF_INET,SOCK_STREAM,0);
    if(listenFd<0){
        perror("socket error");
        exit(1);
    }
    printf("listen on\n");

    int sockFd=socket(AF_INET,SOCK_STREAM,0);
    if(sockFd<0){
        perror("sock error");
    }
    printf("sock on\n");

    struct sockaddr_in sin;
    memset(&sin,0,sizeof(sin));
    sin.sin_family=AF_INET;
    sin.sin_port=htons(SERV_PORT);
    sin.sin_addr.s_addr=inet_addr(SERV_IP);
    int ret=bind(listenFd,(struct sockaddr *)&sin,sizeof(sin));
    if(ret<0){
        perror("bind error");
        exit(1);
    }
    printf("bind on\n");

    ret=listen(listenFd,5);
    if(ret<0){
        perror("listen error");
    }
    printf("listen on\n");

    int conFd=accept(listenFd,NULL,NULL);
    if(conFd<0){
        perror("accept error");
        exit(1);
    }
    printf("accept on\n");

    sleep(5);

    struct sockaddr_in sins;
	memset(&sins, 0, sizeof(sins));
	sins.sin_family = AF_INET;
	sins.sin_port = htons(CLNT_PORT);
	sins.sin_addr.s_addr = inet_addr(CLNT_IP);
	int retc = connect(sockFd, (struct sockaddr *)&sins, sizeof(sins));
	if (retc < 0) {
		perror("connect error\n");
		exit(1);
	}
	printf("connect ok\n");

    char buf[BUFSIZ];
    char bufre[]={"信息已接收\n"};

    while(1){
        do{
            memset(buf,0,sizeof(buf));
            ret=recv(conFd,buf,sizeof(buf)-1,0);
        }while(ret<0 && errno==EINTR);

        if(ret<0){
            perror("recv error");
            continue;
        }
        if(ret==0){
            printf("client exit\n");
            break;
        }
        printf("recv:%s",buf);
        send(sockFd, bufre, strlen(bufre), 0);
    }
    close(sockFd);
    close(conFd);
    close(listenFd);
    
    return 0;
}