#include<stdio.h>
#include <unistd.h>

int main()
{
	char  *arr1[]={"aaa","bbb","ccc",NULL};
	char  *arr2[]={"PWD=xxx","FFF",NULL};
	if(-1==execve("./test",arr1,arr2))
	{
		printf("execve error!-----------\r\n");
		return -1;
	}
	printf("hello world\r\n");	
	return 0;
}
