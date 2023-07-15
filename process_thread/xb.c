#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(int argc, const char *argv[])
{
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
		int fw2=open("myfifo2",O_WRONLY);
		if(fw2<0)
		{
			perror("open myfifo2 error");
			return -1;
		}
		while(1)
		{
			fgets(buf,sizeof(buf),stdin);
			write(fw2,buf,sizeof(buf));
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
		fw1=open("myfifo1",O_RDONLY);
		if(fw1<0)
		{
			perror("open myfifo1 error");
			return -1;
		}
		while(1)
		{
			waitpid(-1,NULL,WNOHANG);
			memset(buf,0,sizeof(buf));
			read(fw1,buf,sizeof(buf));
			printf("%s",buf);
			if(strncmp(buf,"exit",4)==0)
			{
				break;
			}
		}
		close(fw1);
	}
	return 0;
}