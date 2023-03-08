//最终输出1024个，原因是缓冲区写满，自动刷新
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
	_exit(-1);
}