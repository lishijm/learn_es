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
    int listenFd=socket(AF_INET,SOCK_STREAM,0);
    if(listenFd<0){
        perror("socket error");
        exit(1);
    }
    
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

    fd_set rset,tset;
    FD_ZERO(&rset);
    FD_SET(listenFd,&rset);
    FD_SET(0,&rset);
    int maxFd=listenFd;
    char buf[BUFSIZ];
    int conFd,i;
    struct sockaddr_in cin;
    socklen_t len;

    while(1){
        tset=rset;
        ret=select(maxFd+1,&tset,NULL,NULL,NULL);
        if(ret<0){
            perror("select error");
            continue;
        }
        for(i=0;i<(maxFd+1);i++){
            if(FD_ISSET(i,&tset)==0){
                continue;
            }
            //标准输入数据发生
            if(i==0){
                memset(buf,0,sizeof(buf));
                if(fgets(buf,sizeof(buf),stdin)==NULL){
                    printf("fgets error\n");
                    continue;
                }
                if(strncasecmp(buf,QUIT_STR,strlen(QUIT_STR))==0){
                    printf("input quit,server exit\n");
                    exit(0);
                }
            }
            //listenFd数据发生-->转入accept
            else if(i==listenFd){
                memset(&cin,0,sizeof(cin));
                len=sizeof(cin);
                conFd=accept(listenFd,(struct sockaddr *)&cin,&len);
                if(conFd<0){
                    perror("accept error");
                    continue;
                }
                if(conFd>maxFd){
                    maxFd=conFd;
                }
                //将conFd加入select关注
                FD_SET(conFd,&rset);
            }
            else{
                do{
                    memset(buf,0,sizeof(buf));
                    ret=recv(i,buf,sizeof(buf)-1,0);
                }while(ret<0&&errno==EINTR);
                if(ret<0){
                    perror("recv error");
                    continue;
                }
                if(ret==0){
                    FD_CLR(i,&rset);
                    close(i);
                    continue;
                }
                printf("recv:%s",buf);
            }
        }
        /*
        for(i=0;i<16;i++){
            printf("%ld",rset[i]);
        }
        printf("rset:%ld\n",rset);
        */
    }
    close(listenFd);
    close(conFd);
    close(maxFd);

    return 0;
}