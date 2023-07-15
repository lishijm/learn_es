//多进程并发TCP
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>
#include <pthread.h>

#define SERV_PORT 5051

void client_handler(int conFd){
    char buf[BUFSIZ];
    int ret;
    while(1){
        do{
            memset(buf,0,sizeof(buf));
            ret=recv(conFd,buf,sizeof(buf)-1,0);
        }while(ret<0&&errno==EINTR);
        if(ret<0){
            perror("recv error");
            continue;
        }
        if(ret==0){
            printf("client exit\n");
            break;
        }
        printf("recv%s",buf);
    }
    close(conFd);
}

void sig_handler(int signo){
    pid_t pid=waitpid(-1,NULL,WNOHANG);
    if(pid>0){
        printf("child pid=%d exit\n",pid);
    }
    else{
        printf("pid=%d\n",pid);
    }
}

int main(){
    //回收子进程资源
    signal(SIGCHLD,sig_handler);

    //创建套接字
    int listenFd=socket(AF_INET,SOCK_STREAM,0);
    if(listenFd<0){
        perror("sockket error");
        exit(1);
    }
    printf("socket ok\n");
    //允许本地地址和端口号快速重用
    int on=1;
    setsockopt(listenFd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on));
    //绑定IP地址和端口号
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
    //设置监听套接字
    ret=listen(listenFd,5);
    if(ret<0){
        perror("listen error");
        exit(1);
    }
    printf("listen ok\n");

    int conFd;
    struct sockaddr_in cin;
    socklen_t len;
    pid_t pid;
    while(1){
        //接受客户端的连接
        memset(&cin,0,sizeof(cin));
        len=sizeof(cin);
        conFd=accept(listenFd,(struct sockaddr *)&cin,&len);
        if(conFd<0){
            perror("accept error");
            continue;
        }
        printf("cliet(%s:%d)connect ok\n",inet_ntoa(cin.sin_addr),ntohs(cin.sin_port));
        //创建子进程为客户端提供服务
        pid=fork();
        if(pid<0){
            perror("fork error");
            continue;
        }
        else if(pid==0){
            close(listenFd);
            client_handler(conFd);
            exit(0);
        }
        else{
            close(conFd);
        }
    }
    //关闭套接字
    close(listenFd);
    return 0;
}