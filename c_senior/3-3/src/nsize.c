#include"../include/class.h"
void nsize(stu (*p)[3]){
    int i,j;
    stu tmp;

    for(i=0;i<3;i++){
        for(j=0;j<3-i-1;j++){
            if((strcmp((((*p)+j)->name),(((*p)+j+1)->name)))>0){
                tmp=*((*p)+j+1);
                *((*p)+j+1)=*((*p)+j);
                *((*p)+j)=tmp;
            }
        }
    }
}