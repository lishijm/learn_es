#include "../include/20.h"

int insetrlink(link *phead){
    link *c1;
    link *c2;
    link *c3;
    c1=(link *)malloc(sizeof(link));
    c2=(link *)malloc(sizeof(link));
    c3=(link *)malloc(sizeof(link));
    c1->data='2';
    c2->data='0';
    c3->data='%';
    link *ptmp=NULL;
    ptmp=phead->next;
    while(ptmp!=NULL){
        if(ptmp->data==' '){
            c3->next=ptmp->next;
            ptmp->data=c1->data;
            ptmp->next=c2;
            c2->next=c3;
            c1->data='2';
            c2->data='0';
            c3->data='%';
        }
        ptmp=ptmp->next;
    }
    return 0;
}