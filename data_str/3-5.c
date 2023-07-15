//顺序队列
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define max 5
int flag=1;
typedef int datat;

typedef struct quenue{
    datat arr[max];
    int top;
    int rear;
} que;

que *creaquenode(void){
    que *tmp=NULL;
    tmp=(que *)malloc(sizeof(que));
    if(NULL==tmp){
        puts("creat err");
    }
    memset(tmp,0,sizeof(que));

    return tmp;
}

que *inique(que *p){
    p->top=p->rear=0;
    return p;
}

void quein(que *p,datat ele){
    if(p->rear>=max){
        printf("空间已满\n");
        p->rear=0;
        flag=0;
    }
    else{
        p->arr[p->rear]=ele;
        p->rear++;
    }
}

void queout(que *p){
    if(1==flag){
        while(p->top<p->rear){
            printf("%d\n",p->arr[p->top]);
            p->top++;
        }
    }
    else{
        while(p->top<5){
            printf("%d\n",p->arr[p->top]);
            p->top++;
        }
    }
}
int main(){
    que *pq=NULL;
    pq=creaquenode();
    pq=inique(pq);

    quein(pq,11);
    quein(pq,22);
    quein(pq,33);
    quein(pq,44);
    quein(pq,55);
    quein(pq,66);
    queout(pq);

    return 0;
}