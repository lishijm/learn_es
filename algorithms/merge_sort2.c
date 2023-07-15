#include<stdio.h>
#include<stdlib.h>

typedef struct linknode{
    struct linknode *next;
    int val;
} node;

node *creat_node(void){
    node *np=NULL;
    np=(node *)malloc(sizeof(node));
    memset(np,0,sizeof(node));
    return np;
}

int main(){
    node *phead=NULL;
    phead=creat_node();
    node *tmp=phead;
    phead->next=tmp;
    int num,i;
    for(i=0;i<5;i++){
        scanf("%d",&num);
        node *new=NULL;
        new=creat_node();
        new->val=num;
        tmp->next=new;
        tmp=tmp->next;
    }
}