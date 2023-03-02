#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int flag=1;
int flagmain=1;
int stop=0;

typedef int datat;

typedef struct btre{
    struct btre *left;
    datat data;
    struct btre *right;
    struct btre *up;
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

btr *firstave(btr *p,datat fele){
    
    printf("%p\n",p);
    printf("%d\n",p->data);
    printf("\n");
    if(p->data==fele){
        return p;
        stop=1;
    }
    else if(stop==0){
        *firstave(p->left,fele);
        *firstave(p->right,fele);
    }
}


void cenextnode(btr *tree,datat fele){
    btr *fp=NULL;
    fp=firstave(tree,fele);
    printf("x%p\n",fp->up);
    if(fp->up!=NULL&&fp->right==NULL&&fp->left==NULL){
        if(fp->up->left==fp){
            printf("%d",fp->up->data);
        }
        else if(fp->up->right==fp){
            if(fp->up->up!=NULL){
                printf("%d",fp->up->up->data);
            }
        }
    }
    else if(fp->right!=NULL){
        printf("%d",fp->right->data);
    }
    if (fp->right==NULL&&fp->up->up==NULL&&fp->up->right==fp){
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