#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SERV_IP "192.168.8.226"
#define SERV_PORT 5001

int main()
{
	// 1.创建套接字
	int sockFd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockFd < 0) {
		perror("socket error");
		exit(1);
	}
	printf("socket ok");

	// 2.连接服务器
	struct sockaddr_in sin;
	memset(&sin, 0, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(SERV_PORT);
	sin.sin_addr.s_addr = inet_addr(SERV_IP);
	int ret = connect(sockFd, (struct sockaddr *)&sin, sizeof(sin));
	if (ret < 0) {
		perror("connect error\n");
		exit(1);
	}
	printf("connect ok\n");

	// 3.发消息
	char buf[BUFSIZ];

	while (1) {
		printf("input:");
		memset(buf, 0, sizeof(buf));
		if (fgets(buf, sizeof(buf), stdin) == NULL) {
			printf("fgets error\n");
			continue;
		}
		send(sockFd, buf, strlen(buf), 0);
	}

	// 4.关闭套接字
	close(sockFd);
	return 0;
}
