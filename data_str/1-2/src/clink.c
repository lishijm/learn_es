#include "../include/link.h"

link *clink(void){
    link *p=NULL;
    p=(link *)malloc(sizeof(link));
    memset(p,0,sizeof(link));
}