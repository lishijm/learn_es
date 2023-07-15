#include"../include/list.h"

int del(list *p,int pos){
    int i=0;
    for(i=0;i<5-pos-1;i++){
        p->arr[pos+i]=p->arr[pos+i+1];
    }
    p->arr[5]=0;

    return 0;
}