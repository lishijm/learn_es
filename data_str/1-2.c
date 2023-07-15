#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef int datat;

typedef struct link{
    datat data;
    struct link *next;
} link;

link *crlink(void){
    link *plink=NULL;
    plink=(link *)malloc(sizeof(link));
    memset(plink,0,sizeof(link));
    return plink;
}

void makelink(link *phead1){
    link *ptmp1=NULL;
    ptmp1=crlink();
    
    phead1->next=ptmp1;

    int i;
    for(i=1;i<100;i++){
        link *a=NULL;
        a=crlink();
        a->data=i;
        ptmp1->next=a;
        ptmp1=ptmp1->next;
    }
}
void delink(link *p){
    link **del=NULL;
    
    del=(p->next);
    
    while(p->next!=NULL){
        
        p->next=(p->next)->next;
        free(*del);
        
        *del=p->next;
        
    }
    *del=p;
    free(*del);
}
void output(link *p){
    link *ptmp=NULL;
    ptmp=crlink();
    ptmp=p;
    while(ptmp->next!=NULL){
        ptmp=ptmp->next;
        printf("%d ",ptmp->data);
    }
    printf("\n");
}

int main(){
    link *phead=NULL;
    phead=crlink();

    makelink(phead);
    delink(phead);
    output(phead);


    return 0;
}