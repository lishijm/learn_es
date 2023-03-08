//最终输出1030个，原因是fflush强制刷新缓冲区
#include <stdio.h>
#include <string.h>
#include <unistd.h>
int main(int argc,char *argv[]){
	char teststr[1030];
	int i;
	for(i=0;i<1030;i++){
		teststr[i]='a';
	}
	FILE *fp;
	fp=fopen(argv[1],"w");
	fwrite(teststr,1,sizeof(teststr),fp);
	fflush(NULL);
    _exit(-1);
}