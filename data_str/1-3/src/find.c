#include "../include/find.h"

int find(list *p,int fn){
    int i;
    for(i=0;i<20;i++){
        if(p->arr[i]==fn){
            break;
        }
    }
    return i;
}