#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc,char *argv[]){

    FILE *r=NULL;
    FILE *w=NULL;
    r=fopen(argv[1],"rb");
    w=fopen(argv[2],"wb");
    char buf[1024];
    int rrn;

    if(NULL==r){
        puts("open file err.");
    }
    if(NULL==w){
        puts("open file err.");
    }
    
    while(0==feof(r)){
        memset(buf,0,1024);
        rrn=fread(buf,4,1024,r);
        fwrite(buf,4,rrn,w);
    }

    fclose(r);
    fclose(w);

    return 0;
}