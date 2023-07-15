//设置socket实现超时
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/select.h>

#define SERV_PORT 5001
int main()
{
   // 1.创建套接字
	int sockFd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sockFd < 0) {
		perror("socket error");
		exit(1);
	}
	printf("socket ok\n");
    
    //设置接收消息超时时间位5秒
    struct timeval tv;
    tv.tv_sec=5;
    tv.tv_usec=0;
    
    /**/
    setsockopt(sockFd,SOL_SOCKET,SO_RCVTIMEO,&tv,sizeof(tv));
    /**/
    
    // 2.绑定IP地址和端口号
	struct sockaddr_in sin;
	memset(&sin, 0, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(SERV_PORT);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	int ret = bind(sockFd, (struct sockaddr *)&sin, sizeof(sin));
	if (ret < 0) {
		perror("bind error");
		exit(1);
	}
	printf("bind ok\n");

	char buf[BUFSIZ];
	char buf1[BUFSIZ + 20];
	struct sockaddr_in cin;
	socklen_t len;

    while (1) {
		// 3.收消息
		do {
			memset(buf, 0, sizeof(buf));
			memset(&cin, 0, sizeof(cin));
			len = sizeof(cin);
			ret = recvfrom(sockFd, buf, sizeof(buf) - 1, 0, (struct sockaddr *)&cin, &len);
			printf("recvfrom timeout, ret=%d, errno=%d\n", ret, errno);
		} while (ret < 0 && (errno == EINTR || errno == EAGAIN));

		// 接收消息出错
		if (ret < 0) {
			perror("recvfrom error");
			continue;
		}
		printf("recvfrom(%s:%d):%s", inet_ntoa(cin.sin_addr), ntohs(cin.sin_port), buf);

		// 4.发消息
		memset(buf1, 0, sizeof(buf1));
		sprintf(buf1, "server response:%s", buf);
		printf("sendto:%s", buf1);
		sendto(sockFd, buf1, strlen(buf1), 0, (struct sockaddr *)&cin, len);
	}

	// 5.关闭套接字
	close(sockFd);
	return 0;
}