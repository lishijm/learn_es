#include<stdio.h>
#include <stdlib.h>


int main(int argc,char *argv[],char *envp[])
{
	while(argc--)
	{
		printf("%s\r\n",*argv++);
	}
	printf("----------------------------------\r\n");
	while(*envp)
	{
		printf("%s\r\n",*envp++);
	}
	printf("%s\r\n",getenv("PWD"));
	return 0;
}