#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int datat;   //int -->  datat

typedef struct queue{
	datat data[5];
	int first;
	int last;
} qu;

qu *crqe(void){
	qu *pq = NULL;
	pq = (qu *)malloc(sizeof(qu));
	memset(pq, 0, sizeof(qu));
	return pq;
}

void in(qu *pq,datat inel){
    pq->data[pq->last]=inel;
    pq->last++;
}

void out(qu *pq,datat onum){
    int i;
    for(i=0;i<onum;i++){
        pq->data[pq->first]=pq->data[(pq->first)+1];
        (pq->first)++;
    }
}

void print(qu *p){
    while(p->first!=p->last){
        printf("%d",p->data[p->first]);
        (p->first)++;
    }
}

int main(){

    qu *qh=NULL;
    qh=crqe();
    
    datat inel;
    scanf("%d",&inel);
    in(qh,inel);
    
    int onum;
    scanf("%d",&onum);
    out(qh,onum);
    print(qh);
    int sel;
    scanf("%d",&sel);
    return 0; 
}