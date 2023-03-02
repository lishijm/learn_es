//哈希散列
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int flag=1;

typedef int datat;

typedef struct student{
    datat data;
    char name[20];
} stu;

typedef struct link{
    stu *inf;
    struct link *next;
} link;

link *creanode(void){
    link *plink=NULL;
    plink=(link *)malloc(sizeof(link));
    memset(plink,0,sizeof(link));
    return plink;
}

void makelink(link *phead1,datat ele){
    link *ptmp1=NULL;
    ptmp1=crlink();
    
    phead1->next=ptmp1;
    ptmp1->data=ele;
    int i;
    for(i=1;i<100;i++){
        link *a=NULL;
        a=crlink();
        a->data=i;
        ptmp1->next=a;
        ptmp1=ptmp1->next;
    }
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

    int i;
    link *block[13];
    for(i=0,i<13;i++){
        block[i]=NULL;
    }
    int sel;
    while(flag){    
        scanf("%d",&sel);
        switch (sel){
        case 1:
            //
            break;
        
        default:
            flag=0;
            break;
        }
    }
    makelink(phead);
    output(phead);
    int n;
    scanf("%d",&n);
    
    phead=back(phead,n);
    output(phead);

    return 0;
}