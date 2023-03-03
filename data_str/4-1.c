//循环建立二叉树
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int flag=1;
int flagmain=1;

typedef int datat;

typedef struct btre{
    struct btre *left;
    datat data;
    struct btre *right;
} btr;

btr *cretree(void){
    btr *tmp=NULL;
    tmp=(btr *)malloc(sizeof(btr));
    if(tmp==NULL){
        puts("err");
    }
    memset(tmp,0,sizeof(tmp));
    return tmp;
}

void insert(btr *tree,datat ele){
    btr *tmp;
    btr *new;
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

void firstave(btr *p){
    if(p==NULL){
        return ;
    }
    printf("%d",p->data);
    firstave(p->left);
    firstave(p->right);
}

void centrave(btr *p){
    if(p==NULL){
        return ;
    }
    centrave(p->left);
    printf("%d",p->data);
    centrave(p->right);
}

void lastrave(btr *p){
    if(p==NULL){
        return ;
    }
    lastrave(p->left);
    lastrave(p->right);
    printf("%d",p->data);
}

int main(){
    btr *phead=NULL;
    phead=cretree();
    datat ele;
    int sel;
     while(flagmain){
        scanf("%d",&sel);
        switch (sel){
        case 1:
            scanf("%d",&ele);
            insert(phead,ele);
            break;
        default:
            flagmain=0;
            break;
        }
    }
    printf("先序遍历\n");
    firstave(phead);
    printf("\n");
    printf("中序遍历\n");
    centrave(phead);
    printf("\n");
    printf("后序遍历\n");
    lastrave(phead);
    printf("\n");
    
}