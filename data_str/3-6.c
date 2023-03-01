#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int datat;

typedef struct linestack{
    datat data;
    struct linestack *next;
} kst;

kst *crestack(void){
    kst *tmp=NULL;
    tmp=(kst *)malloc(sizeof(kst));
    if(tmp==NULL){
        puts("err");
    }
    memset(tmp,0,sizeof(tmp));
    return tmp;
}

kst *push(kst *p,datat ele){
    kst *tmp=NULL;
    tmp=crestack();
    tmp->data=ele;
    tmp->next=p->next;
    p->next=tmp;

}

kst *pop(kst *p){
    kst *del=NULL;
    del=crestack();
    del=p;
    if(del->next!=NULL){
        del=del->next;
        printf("弹出:%d\n",del->data);
        if(del->next!=NULL){
            printf("弹出后栈顶:%d\n",del->next->data);
        }
        else{
            printf("弹出后空栈\n");
        }
    }
    else{
        printf("空栈\n");
    }
    return del;
}

kst *cles(kst *p){
    kst *del=NULL;
    del=crestack();

    del=p;
     
    while(del->next->next!=NULL){
        if(del->next->next!=NULL){
            del->next=del->next->next;
        }
        
    }
    
    if(del->next->next==NULL){
        del->next=NULL;
    }
    return del;
}

void output(kst *p){
    kst *ptmp=NULL;
    ptmp=crestack();
    ptmp=p;
    while(ptmp->next!=NULL){
        ptmp=ptmp->next;
        printf("%d ",ptmp->data);
    }
    printf("\n");
}

int main(){
    kst *stack=NULL;
    stack=crestack();

    int flag=1,sel;
    datat ele;
    while(flag){
        scanf("%d",&sel);
        switch (sel){
        case 1:
            scanf("%d",&ele);
            stack=push(stack,ele);
            output(stack);
            break;
        case 2:
            stack=pop(stack);
            break;
        case 3:
            cles(stack);
            output(stack);
            break;
        default:
            flag=0;
            break;
        }
    }

    
    return 0;
}