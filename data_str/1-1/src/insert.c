#include"../include/list.h"

int insert(list *p,int pos,listel posco){
    int i=p->count-1;
    for(i;i>=pos;i--){
        p->arr[i+1]=p->arr[i];
    }
    p->arr[pos]=posco;
    p->count=(p->count)+1;
    
    return 0;
}