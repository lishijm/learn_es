//有问题
//输出中序遍历的下一个值
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
    struct btre *up;
} btr;

btr *fpp;

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
                    new->up=tmp;
                    tmp->left=new;
                    //printf("%p\n",new->up);
                    break;
                }
                tmp=tmp->left;
            }
            else if(new->data>tmp->data){
                if(NULL==tmp->right){
                    new->up=tmp;
                    tmp->right=new;
                    //printf("%p\n",new->up);
                    break;
                }
                tmp=tmp->right;
            }
        }
    }
}

void firstave(btr *p,datat fele){
    if(NULL==p){
        return ;
    }
    printf("%p\n",p);
    printf("%d\n",p->data);
    printf("\n");
    if(p->data==fele){
        fpp=p;
    }
    firstave(p->left,fele);
    firstave(p->right,fele);
}


void cenextnode(btr *tree,datat fele){
    firstave(tree,fele);
    printf("x%d\n",fpp->data);
    if(fpp->up!=NULL&&fpp->right==NULL&&fpp->left==NULL){
        if(fpp->up->left==fpp){
            printf("%d",fpp->up->data);
        }
        else if(fpp->up->right==fpp){
            if(fpp->up->up!=NULL){
                printf("%d",fpp->up->up->data);
            }
        }
    }
    else if(fpp->right!=NULL){
        printf("%d",fpp->right->data);
    }
    if (fpp->right==NULL&&fpp->up->up==NULL&&fpp->up->right==fpp){
            printf("后面没有");
    }
}

void centrave(btr *p){
    if(p==NULL){
        return ;
    }
    centrave(p->left);
    printf("%d",p->data);
    centrave(p->right);
}

int main(){
    btr *phead=NULL;
    phead=cretree();
    
    int sel,length,i;
    scanf("%d",&length);
    datat ele,fele, arr[length];
    for(i=0;i<length;i++){
        scanf("%d",&ele);
        arr[i]=ele;
    }
     while(flagmain){
        scanf("%d",&sel);
        switch (sel){
        case 1:
            for(i=0;i<length;i++){
                insert(phead,arr[i]);
            }
            break;
        case 2:
            scanf("%d",&fele);
            cenextnode(phead,fele);
            break;
        default:
            flagmain=0;
            break;
        }
    }

    printf("中序遍历\n");
    centrave(phead);
    printf("\n");

    return 0;   
}