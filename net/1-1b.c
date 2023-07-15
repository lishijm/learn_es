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
    if(listenFd<0){
        perror("socket error");
        exit(1);
    }
    printf("sock on\n");

    struct sockaddr_in sinb;
    memset(&sinb,0,sizeof(sinb));
    sinb.sin_family=AF_INET;
    sinb.sin_port=htons(CLNT_PORT);
    sinb.sin_addr.s_addr=inet_addr(CLNT_IP);
    int ret=bind(listenFd,(struct sockaddr *)&sinb,sizeof(sinb));
    if(ret<0){
        perror("bind error");
        exit(1);
    }
    printf("bind on\n");

    struct sockaddr_in sinc;
	memset(&sinc, 0, sizeof(sinc));
	sinc.sin_family = AF_INET;
	sinc.sin_port = htons(SERV_PORT);
	sinc.sin_addr.s_addr = inet_addr(SERV_IP);
	int retc = connect(sockFd, (struct sockaddr *)&sinc, sizeof(sinc));
	if (retc < 0) {
		perror("connect error");
		exit(1);
	}
	printf("connect ok\n");

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

    char bufs[BUFSIZ];
    char bufl[BUFSIZ];
    while(1){
        printf("input:");
		memset(bufs, 0, sizeof(bufs));
		if (fgets(bufs, sizeof(bufs), stdin) == NULL) {
			printf("fgets error\n");
			continue;
		}
		send(sockFd, bufs, strlen(bufs), 0);
        do {
			memset(bufl, 0, sizeof(bufl));
			ret = recv(conFd, bufl, sizeof(bufl) - 1, 0);
		} while (ret < 0 && errno == EINTR);
        printf("recv:%s", bufl);

	}
    close(sockFd);
    close(conFd);
    close(listenFd);
    
    return 0;
}