//UNIX套接字服务器
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/un.h>

#define UNIX_DOMAIN_FILE "unix_domain.sock"

int main()
{
    // 如果unix域套接字文件存在，删除该文件
    if(access(UNIX_DOMAIN_FILE,F_OK)==0){
        unlink(UNIX_DOMAIN_FILE);
    }
    //创建套接字
    int listenFd=socket(AF_UNIX,SOCK_STREAM,0);
    if(listenFd<0){
        perror("socket error");
        exit(1);
    }
    //绑定IP
    struct sockaddr_un sun;
    memset(&sun,0,sizeof(sun));
    sun.sun_family=AF_UNIX;
    strcpy(sun.sun_path,UNIX_DOMAIN_FILE);
    int ret=bind(listenFd,(struct sockaddr *)&sun,sizeof(sun));
    if(ret<0){
        perror("bind perror");
        exit(1);
    }
    printf("bind ok\n");
    //设置监听套接字
    ret=listen(listenFd,5);
    if(ret<0){
        perror("listen error");
        exit(1);
    }
    printf("listen ok\n");
    //等待连接
    int conFd=accept(listenFd,NULL,NULL);
    if(conFd<0){
        perror("accept error");
        exit(1);
    }
    printf("accept ok\n");
    //收消息
    char buf[BUFSIZ];
    char buf1[BUFSIZ+20];
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
        printf("recv:%s",buf);
    }

    close(conFd);
    close(listenFd);

    return 0;
}