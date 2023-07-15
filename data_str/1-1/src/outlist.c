#include"../include/list.h"

int output(list *p){
    int i=0;
    for(i;i<5;i++){
        printf("%d",p->arr[i]);
    }

    return 0;
}