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
    p->top=0;
	p->rear=max-1;
    return p;
}

void quein(que *p,datat ele){
	if(ele%2==0){
		p->arr[p->rear]=ele;
		p->rear--;
	}
	else{
		p->arr[p->top]=ele;
		p->top++;
	}
}

void queout(que *p){
    int i;
	for(i=0;i<max;i++){
		printf("%d",p->arr[i]);
	}
}
int main(){
    que *pq=NULL;
    pq=creaquenode();
    pq=inique(pq);

	datat arr[5]={1,2,3,4,5},i;
	for(i=0;i<5;i++){
		quein(pq,arr[i]);
	}
	queout(pq);

    return 0;
}