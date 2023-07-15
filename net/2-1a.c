#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SERV_PORT 5001

int main()
{
	// 1.创建套接字
	int listenFd = socket(AF_INET, SOCK_STREAM, 0);
	if (listenFd < 0) {
		perror("socket error");
		exit(1);
	}
	printf("socket ok\n");

	// 2.绑定IP地址和端口号
	struct sockaddr_in sin;
	memset(&sin, 0, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(SERV_PORT);
	sin.sin_addr.s_addr = htons(INADDR_ANY);//设置全零监听
	int ret = bind(listenFd, (struct sockaddr *)&sin, sizeof(sin));
	if (ret < 0) {
		perror("bind error");
		exit(1);
	}
	printf("bind ok\n");

	// 3.设置监听套接字（把主动套接字改为被动套接字）
	ret = listen(listenFd, 5);
	if (ret < 0) {
		perror("listen error");
		exit(1);
	}
	printf("listen ok\n");

	// 4.等待客户端的连接
	int connFd = accept(listenFd, NULL, NULL);
	if (connFd < 0) {
		perror("accept error");
		exit(1);
	}
	printf("accept ok\n");

	// 5.收消息
	char buf[BUFSIZ];

	while (1) {
		do {
			memset(buf, 0, sizeof(buf));
			ret = recv(connFd, buf, sizeof(buf) - 1, 0);
		} while (ret < 0 && errno == EINTR);

		// 接收消息出错
		if (ret < 0) {
			perror("recv error");
			continue;
		}

		// 对端关闭了套接字
		if (ret == 0) {
			printf("client exit\n");
			break;
		}

		printf("recv:%s", buf);
	}

	// 6.关闭套接字
	close(connFd);
	close(listenFd);
	return 0;
}
