#include"./include/filerw.h"

int main(int argc,char *argv[]){

    char *filename1=argv[1];
    char *filename2=argv[2];
    int sel,flag=0;

    while(1){
        scanf("%d",&sel);
        switch(sel){
            case 1:
                filecp(filename1,filename2);
                break;
            case 2:
                filesct(filename1);
                break;
            default:
                flag=1;
                break;
        }
        if(flag==1){
            break;
        }
    }

    return 0;
}