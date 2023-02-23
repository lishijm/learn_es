#include<stdio.h>
#include<string.h>
#include<time.h>
int main(int argc,char *argv[]){
    FILE *fp=NULL;
    fp=fopen(argv[1],"w");

    time_t now;
    int rt=time(&now);
    if(rt==-1){
        fclose(fp);
        printf("time error");
        return -1;
    }
    char *pt=ctime(&now);

    fwrite(pt,strlen(pt),1,fp);
    fclose(fp);

    return 0;
}