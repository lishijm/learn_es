#include "../include/find.h"

list *crlist(void){
    list *plist;
    plist=(list *)malloc(sizeof(list));
    memset(plist,0,sizeof(list));
    return plist;
}