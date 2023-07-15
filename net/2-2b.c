#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>

#define QUIT_STR "quit"

int main(int argc,char *argv[]){
    if(argc!=3){
        exit(1);
    }
    int port=atoi(argv[2]);
    if(port<=5000||port>65535){
        exit(1);
    }
    
    int sockFd=socket(AF_INET,SOCK_DGRAM,0);
    if(sockFd<0){
        perror("socket error");
        exit(1);
    }
    printf("socket ok\n");

    struct sockaddr_in sin;
    sin.sin_family=AF_INET;
    sin.sin_port=htons(port);
    sin.sin_addr.s_addr=inet_addr(argv[1]);

    int ret;
    char buf[BUFSIZ+20];

    while(1){
        memset(buf,0,sizeof(buf));
        printf("intput:\n");
        if(fgets(buf,sizeof(buf),stdin)==NULL){
            printf("fgets error\n");
            continue;
        }
        if (strncasecmp(buf, QUIT_STR, strlen(QUIT_STR)) == 0) {
			printf("input quit, client exit\n");
			break;
		}
        sendto(sockFd,buf,strlen(buf),0,(struct sockaddr *)&sin,sizeof(sin));
        memset(buf,0,sizeof(buf));
        ret=recvfrom(sockFd,buf,sizeof(buf)-1,0,NULL,NULL);
        if(ret<0){
            perror("recvfrom error");
            continue;
        }
        printf("recvfrom%s",buf);
    }
    close(sockFd);

    return 0;
}