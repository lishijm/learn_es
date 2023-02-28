#include "../include/find.h"

int main(){
    int i;
    list *p=crlist();
    for(i=0;i<20;i++){
        p->arr[i]=i+1;
    }
    int fn;
    scanf("%d",&fn);
    i=find(p,fn);
    printf("%d\n",i);

    return 0;
}