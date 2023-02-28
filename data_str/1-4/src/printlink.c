#include "../include/20.h"

int printlink(link *phead){
    link *ptmp=NULL;
    ptmp=phead->next;
    while(ptmp!=NULL){
        printf("%c",ptmp->data);
        ptmp=ptmp->next;
    }
    printf("\n");

    return 0;
}