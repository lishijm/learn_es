//哈希散列
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int flag=1;

typedef int datat;

typedef struct student{
    datat data;
    char name[20];
} stu;

typedef struct link{
    stu *inf;
    struct link *next;
} link;

stu *creainf(void){
    stu *ninf=NULL;
    ninf=(stu *)malloc(sizeof(stu));
    memset(ninf,0,sizeof(stu));
    return ninf;
}

link *creanode(void){
    link *plink=NULL;
    plink=(link *)malloc(sizeof(link));
    memset(plink,0,sizeof(link));
    return plink;
}

stu *makeinf(void){
    stu *newinf=NULL;
    newinf=creainf();
    scanf("%d",&newinf->data);
    scanf("%s",newinf->name);

    return newinf;
}

link *makenode(){
    link *newnode=NULL;
    newnode=creanode();
    stu *newinf=NULL;
    newinf=makeinf();
    newnode->inf=newinf;

    return newnode;
}

link* makehashlink(link *block[],link *new,int legnth){
    link *tmp;
    int in;
    in=((new->inf->data)%legnth)-1;
    tmp=block[in];
    new->next=tmp->next;
    tmp->next=new;
}

void serach(link *block[],datat fele,int legnth){
    int i=0,flag=1;
    link *tmp;
    tmp=creanode();
    for (i=0;i<legnth;i++){
        tmp=block[i];
        while(tmp->next!=NULL){
            if(tmp->next->inf->data==fele){
                printf("at NO.%d link\n",i+1);
                flag=0;
                break;
            }
            tmp=tmp->next;
        }
        if(0==flag){
            break;
        }
    }
    if(1==flag){
        printf("not exist\n");
    }
    
}

int main(){

    int i,legnth,in;
    datat fele;
    scanf("%d",&legnth);
    link *block[legnth];

    for(i=0;i<legnth;i++){
        block[i]=NULL;
        block[i]=creanode();
    }
    int sel;
    while(flag){    
        scanf("%d",&sel);
        switch (sel){
        case 1:
            link *new=NULL;
            new=creanode();
            new=makenode();
            makehashlink(block,new,legnth);
            break;
        case 2:
            scanf("%d",&fele);
            serach(block,fele,legnth);
            break;
        default:
            flag=0;
            break;
        }
    }
    
    return 0;
}