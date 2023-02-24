#include<stdio.h>
#include<string.h>
#include<unistd.h>
int main(int argc,char *argv[]){
    int i;
    FILE *fp=NULL;
    fp=fopen(argv[1],"w");
    char tbuf[4095];
    for(i=0;i<4095;i++){
        tbuf[i]='a';
    }
    fwrite(tbuf,1,4095,fp);
    //fflush(NULL);
	_exit(-1);
    //fclose(fp);
    
    return 0;
}