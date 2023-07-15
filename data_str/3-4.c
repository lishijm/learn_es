#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int flag=1;

typedef int datat;

typedef struct bintree{
    struct bintree *left;
    struct bintree *right;
    datat data;
} btre;

btre *cretree(void){
    btre *tmp=NULL;
    tmp=(btre *)malloc(sizeof(btre));
    if(tmp==NULL){
        puts("err");
    }
    memset(tmp,0,sizeof(tmp));
    return tmp;
}

void insert(btre *tree,datat ele){
    btre *tmp;
    btre *new;
    tmp=cretree();
    new=cretree();
    tmp=tree;
    new->data=ele;

    if(flag){
        tree->data=ele;
        flag=0;
    }
    else{
        while(1){
            if(new->data<=tmp->data){
                if(NULL==tmp->left){
                    tmp->left=new;
                    break;
                }
                tmp=tmp->left;
            }
            else if(new->data>tmp->data){
                if(NULL==tmp->right){
                    tmp->right=new;
                    break;
                }
                tmp=tmp->right;
            }
        }
    }
}

int main(){
    btre *phead=NULL;
    phead=cretree();
    datat ele;
    while(1){
        scanf("%d",&ele);
        insert(phead,ele);
    }

    return 0;
    
}