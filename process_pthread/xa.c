#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(int argc, const char *argv[])
{
	unlink("myfifo1");
	unlink("myfifo2");
	if(mkfifo("myfifo1",0777)<0)
	{
		perror("fifo1 create error");
		return -1;
	}
	else
	{
		printf("mkfifo1 OK!\n");
	}
	if(mkfifo("myfifo2",O_CREAT|0777)<0)
	{
		perror("fifo2 create error");
		return -1;
	}
	else
	{
		printf("mkfifo2 OK!\n");
	}
	char buf[20]={'\0'};
	pid_t pid;
	pid=fork();
	if(pid<0)
	{
		perror("fork error");
		return -1;
	}
	else if(0==pid)
	{
		int fw2=open("myfifo2",O_RDONLY);
		if(fw2<0)
		{
			perror("open myfifo2 error");
			return -1;
		}
		while(1)
		{
			memset(buf,0,sizeof(buf));
			read(fw2,buf,sizeof(buf));
			printf("%s",buf);
			if(strncmp(buf,"exit",4)==0)
			{
				break;
			}
		}
		close(fw2);
		exit(0);
	}
	else if(pid>0)
	{
		int fw1=0;
		fw1=open("myfifo1",O_WRONLY);
		if(fw1<0)
		{
			perror("open myfifo1 error");
			return -1;
		}
		while(1)
		{
            waitpid(-1,NULL,WNOHANG);
			fgets(buf,sizeof(buf),stdin);
			write(fw1,buf,sizeof(buf));
			if(strncmp(buf,"exit",4)==0)
			{
				break;
			}
		}
		close(fw1);
	}
	return 0;
}