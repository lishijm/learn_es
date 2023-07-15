// select超时服务器
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/select.h>

#define SERV_PORT 5002
#define QUIT_STR "quit"

int main()
{
	// 1.创建套接字
	int listenFd = socket(AF_INET, SOCK_STREAM, 0);
	if (listenFd < 0) {
		perror("socket error");
		exit(1);
	}
	printf("socket ok\n");

	// 允许地址和端口号快速重用
	int on = 1;
	setsockopt(listenFd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));

	// 2.绑定IP地址和端口号
	struct sockaddr_in sin;
	memset(&sin, 0, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(SERV_PORT);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	int ret = bind(listenFd, (struct sockaddr *)&sin, sizeof(sin));
	if (ret < 0) {
		perror("bind error");
		exit(1);
	}
	printf("bind ok\n");

	// 3.设置监听套接字
	ret = listen(listenFd, 5);
	if (ret < 0) {
		perror("listen error");
		exit(1);
	}
	printf("listen ok\n");

	fd_set rset, tset;
	FD_ZERO(&rset);
	FD_SET(0, &rset);
	FD_SET(listenFd, &rset);

	int maxFd = listenFd;
	char buf[BUFSIZ];
	int connFd;
	struct sockaddr_in cin;
	socklen_t len;
	struct timeval tv = {5, 0};
    while (1){
        tset =rset;
        tv.tv_sec=5;
        ret=select(maxFd+1,&tset,NULL,NULL,&tv);
        if(ret<0){//select出错
            perror("select error");
            continue;
        }
        //select超时
        if(ret==0){
            printf("select timeout,tv_sec=%ld,tv_usec%ld\n",tv.tv_sec,tv.tv_usec);
            continue;
        }
        for(int i=0;i<=maxFd;i++){
            //文件描述符对应的IO通道没有数据发生
            if(FD_ISSET(i,&tset)==0){
                continue;
            }
            //标准输入上有数据发生
            if(i==0){
                memset(buf,0,sizeof(buf));
                if(fgets(buf,sizeof(buf),stdin)==NULL){
                    printf("fgets error\n");
                    continue;
                }
                //输入quit
                if(strncasecmp(buf,QUIT_STR,strlen(QUIT_STR))==0){
                    printf("input quit,server exit\n");
                    exit(0);
                }
            }
            else if(i==listenFd){
                memset(&cin,0,sizeof(cin));
                len=sizeof(cin);
                connFd=accept(listenFd,(struct sockaddr *)&cin,&len);
                if(connFd<0){
                    perror("accept error");
                    continue;
                }
                printf("client(%s:%d) connect ok\n", inet_ntoa(cin.sin_addr), ntohs(cin.sin_port));
                //更新maxFd
                if(connFd>maxFd){
                    maxFd=connFd;
                }
                FD_SET(connFd,&rset);
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
    }
    close(listenFd);
    return 0;
    
}