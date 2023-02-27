#include"../include/list.h"

list *creatlist(void){
    list *plist;
    plist=(list *)malloc(sizeof(list));
    if(NULL==plist){
        puts("err");
        return NULL;
    }
    memset(plist,0,sizeof(list));

    return plist;
}