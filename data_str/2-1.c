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

void back(link *phead,int bn){
    
    link *ptmp1=NULL;
    ptmp1=crlink();
    link *ptmp2=NULL;
    ptmp2=crlink();
    ptmp1=phead->next;
    ptmp2=phead->next;
    
    int i;
    for(i=1;i<bn;i++){
        ptmp1=ptmp1->next;  
    }
    while(ptmp1->next!=NULL){
        ptmp2=ptmp2->next;
        ptmp1=ptmp1->next; 
    }
    
    printf("%d",ptmp2->data);
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
    output(phead);
    int n;
    scanf("%d",&n);
    back(phead,n);

    return 0;
}