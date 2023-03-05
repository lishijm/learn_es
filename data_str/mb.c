#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int flaghead=1;

typedef struct book_information{
    char bookname[32],author[32];
    float price;
    int page,year,ISBN;
} bookinfs;

typedef struct book_node{
    bookinfs *inf;
    struct book_node *next;
} nodes;

bookinfs *creatbookinf(void){
    bookinfs *tmp=NULL;
    tmp=(bookinfs *)malloc(sizeof(bookinfs));
    if(NULL==tmp){
        puts("bookinf malloc ERR");
    }
    memset(tmp,0,sizeof(tmp));
    return tmp;
}

nodes *creatnode(void){
    nodes *tmp=NULL;
    tmp=(nodes *)malloc(sizeof(nodes));
    if(NULL==tmp){
        puts("node malloc ERR");
    }
    memset(tmp,0,sizeof(tmp));
    return tmp;
}

bookinfs *makebookinf(void){
    bookinfs *newinf=NULL;
    newinf=creatbookinf();
    printf("录入时，请依次输入：\n书名 作者名 页数 价格 出版年\n");
    scanf("%s%s%d%f%d%d",newinf->bookname,newinf->author,&newinf->page,&newinf->price,newinf->year,&newinf->ISBN);

    return newinf;
}

nodes *makenode(void){
    nodes *newnode=NULL;
    newnode=creatnode();
    bookinfs *newinf=NULL;
    newinf=makebookinf();
    newnode->inf=newinf;

    return newnode;
}

void makelink(nodes *headnode,nodes *new){
    new->next=headnode->next;
    headnode->next=new;
}

void load_data(struct node *head)
{
	FILE *fp=NULL;
	nodes *new=NULL;
    new=creatnode();
	nodes *temp=head;
    fp=fopen("data.txt","r");
	if(!fp){
		printf("文件打开失败！\n");
		exit(0);
	}
	
    while(1){
		fscanf(fp,"%s%s%d%f%d%d",new->inf->bookname,new->inf->author,&new->inf->page,&new->inf->price,&new->inf->year,&new->inf->ISBN);
		if(feof(fp))
		{
			break;
		}
        new->next=NULL;
		temp->next=new;
		temp=temp->next;
	}
}

void write_data(nodes *head){
    nodes 
    load_data(head);

}

int main(int argc,char *argv[]){
    nodes *headnode=NULL;
    headnode=creatnode();
    int select,flag=1;
    
    FILE *fp;
    
    while(flag){
        scanf("%d",&select);
        switch(select){
        case 1:
            write_data(headnode);
            break;
        default:
            flag=0;
            break;
        }
    }


    return 0;
}