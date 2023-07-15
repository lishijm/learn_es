#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef int datat;

typedef struct wlink{
    datat data;
    struct wlink *before;
    struct wlink *next;
} wlink;

wlink *crlink(void){
    wlink *plink=NULL;
    plink=(wlink *)malloc(sizeof(wlink));
    memset(plink,0,sizeof(wlink));
    return plink;
}

int insert(wlink *p,int pos,datat inel){
    
    wlink *pin=NULL;
    wlink *ptmp=NULL;
    ptmp=crlink();
    pin=crlink();
    (pin->data)=inel;
    int i;
    
    ptmp=p;
    for(i=1;i<pos;i++){
        if(ptmp->next==NULL){
            return -1;
            break;
        }
        ptmp=ptmp->next;
    }
    
    pin->before=ptmp;
    pin->next=ptmp->next;
    if(ptmp->next!=NULL){
        (ptmp->next)->before=pin;
    }
    ptmp->next=pin;

    return 0;
}

void del(wlink *p,int pos){
    wlink *ptmp=NULL;
    ptmp=crlink();
    
    ptmp=p->next;
    int i=1;
    while (ptmp->next!=NULL&&i<pos){
        ptmp=ptmp->next;
        i++;
    }
    (ptmp->before)->next=ptmp->next;
    if(ptmp->next!=NULL){
        (ptmp->next)->before=ptmp->before;
    }
    ptmp->before=NULL;
    ptmp->next=NULL;
}

void output(wlink *p){
    wlink *ptmp=NULL;
    ptmp=crlink();
    ptmp=p;
    while(ptmp->next!=NULL){
        ptmp=ptmp->next;
        printf("%d ",ptmp->data);
    }
    printf("\n");
}

int main(){

    wlink *phead=NULL;
    phead=crlink();

    int sel,pos,flag=1;
    datat inel;

    while(flag){
        scanf("%d",&sel);
        switch(sel){
            case 1:
                scanf("%d",&pos);
                scanf("%d",&inel);
                insert(phead,pos,inel);
                break;
            case 2:
                scanf("%d",&pos);
                del(phead,pos);
                break;
            case 3:
                output(phead);
                break;
            default:
                flag=0;
                break;
        }
    }

    return 0;
}