#include"../include/class.h"

void age(stu (*p)[3]){
    int i,j;
    stu tmp;

    for(i=0;i<3;i++){
        for(j=0;j<3-i-1;j++){
            if(((*p)+j)->age>((*p)+j+1)->age){
                tmp=*((*p)+j+1);
                *((*p)+j+1)=*((*p)+j);
                *((*p)+j)=tmp;
            }
        }
    }
}