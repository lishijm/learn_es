//UNIX套接字客户端
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/un.h>

#define QUIT_STR "quit"
#define UNIX_DOMAIN_FILE "unix_domain.sock"

void usage(char *s)
{
    printf("\n%s unix_domain,",s);
    printf("\n unix_domain_file:unix domain socket file\n");
}

int main(int argc,char *argv[])
{
    if(argc!=2){
        usage(argv[0]);
        exit(1);
    }
    if(0!=access(UNIX_DOMAIN_FILE,F_OK)){
        printf("unix domain socket file not exit\n");
        exit(1);
    }
    int sockFd=socket(AF_UNIX,SOCK_STREAM,0);
    if(sockFd<0){
        perror("socket error");
        exit(1);
    }
    printf("socket ok\n");
    struct sockaddr_un sun;
    memset(&sun,0,sizeof(sun));
    sun.sun_family=AF_UNIX;
    strcpy(sun.sun_path,UNIX_DOMAIN_FILE);
    int ret=connect(sockFd,(struct sockaddr *)&sun,sizeof(sun));
    if(ret<0){
        perror("connect error");
        exit(1);
    }
    printf("conect ok\n");
    char buf[BUFSIZ+20];
    while(1){
        printf("input:\n");
        memset(buf,0,sizeof(buf));
        if(fgets(buf,sizeof(buf),stdin)==NULL){
            printf("fgets error\n");
            continue;
        }
        if(strncasecmp(buf,QUIT_STR,strlen(QUIT_STR))==0){
            printf("client quit\n");
            break;
        }
        send(sockFd,buf,strlen(buf),0);
    }

    close(sockFd);

    return 0;
}