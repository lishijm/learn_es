#include <stdio.h>
#include <stdlib.h>
int main()
{
	int count = 0, ch = 0;
	FILE * fp;
	FILE * cp;
	fp = fopen("data","r");
	char name[20];
		
	while((fscanf(fp,"%s",name))==1)
	{
		cp = fopen(name,"r");
		while((ch=getc(cp))!=EOF)
		{
			if(ch == '\n')
					count++;
		}
	}
	printf("the count %d\n",count);
}