#include"../include/class.h"

void mark(stu (*p)[3],int s){
    int i,j;
    stu tmp;

    for(i=0;i<3;i++){
        for(j=0;j<3-i-1;j++){
            if(((*p)+j)->mark[s]<((*p)+j+1)->mark[s]){
                tmp=*((*p)+j+1);
                *((*p)+j+1)=*((*p)+j);
                *((*p)+j)=tmp;
            }
        }
    }
}