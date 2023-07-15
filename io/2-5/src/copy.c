#include"../include/filerw.h"

int filecp(char *filename1,char *filename2){
    int rrn;
    char buffer[1024];
    FILE *r=fopen(filename1,"rb");
    FILE *w=fopen(filename2,"wb");
    while(0==feof(r)){
        memset(buffer,0,sizeof(buffer));
        rrn=fread(buffer,1,sizeof(buffer),r);
        fwrite(buffer,1,rrn,w);
    }
    fclose(r);
    fclose(w);

    return 0;
}