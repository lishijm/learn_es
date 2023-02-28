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

void twolink(link *phead1,link *phead2){
    link *ptmp1=NULL;
    ptmp1=crlink();
    link *ptmp2=NULL;
    ptmp2=crlink();
    
    phead1->next=ptmp1;
    phead2->next=ptmp2;

    int i;
    for(i=1;i<100;i++){
        link *a=NULL;
        a=crlink();
        a->data=i;
        ptmp1->next=a;
        ptmp1=ptmp1->next;

        if(i%3==0){
            link *b=NULL;
            b=crlink();
            b->data=i;
            ptmp2->next=b;
            ptmp2=ptmp2->next;
        }
    }
}

link *comlink(link *phead1,link *phead2){
    link *clink=NULL;
    clink=crlink();
    link *ptmp1=NULL;
    ptmp1=crlink();
    link *ptmp2=NULL;
    ptmp2=crlink();
    link *ctmp=NULL;
    ctmp=crlink();
    
    ptmp1=phead1->next;
    ptmp2=phead2->next;
    ctmp=clink;
    
    link *mark;
    mark=ptmp1;
    
    while(ptmp2->next!=NULL){
        ptmp1=mark;
        while(ptmp1->next!=NULL){
            if((ptmp2->data)==(ptmp1->data)){
                link *a=NULL;
                a=crlink();
                (a->data)=(ptmp2->data);
                ctmp->next=a;
                ctmp=ctmp->next;
                mark=ptmp1;
                break;
            }
            ptmp1=ptmp1->next;
        }
        ptmp2=ptmp2->next;
        //printf("01 x%d,%p\n",ptmp1->data,ptmp1->next);
        //printf("02 x%d,%p\n",ptmp2->data,ptmp2->next);
    }
    if(ptmp2->next==NULL){
        while(ptmp1->next!=NULL){
            if((ptmp2->data)==(ptmp1->data)){
                link *a=NULL;
                a=crlink();
                (a->data)=(ptmp2->data);
                ctmp->next=a;
                ctmp=ctmp->next;
                mark=ptmp1;
                break;
            }
            ptmp1=ptmp1->next;
        }
        if(ptmp1->next==NULL){
            if((ptmp2->data)==(ptmp1->data)){
                link *a=NULL;
                a=crlink();
                (a->data)=(ptmp2->data);
                ctmp->next=a;
                ctmp=ctmp->next;
                mark=ptmp1;
            }
        }
    }

    return clink;
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
    link *pheada;
    pheada=crlink();
    link *pheadb;
    pheadb=crlink();
    
    twolink(pheada,pheadb);
    
    link *pheadc=NULL;
    pheadc=crlink();
    pheadc=comlink(pheada,pheadb);

    output(pheada);
    output(pheadb);
    output(pheadc);

    return 0;
}