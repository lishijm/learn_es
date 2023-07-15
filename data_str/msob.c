#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct book_information{
    char bookname[32],author[32];
    float price;
    int page,ISBN,year;
} bookinfs;

typedef struct book_node{
    bookinfs *inf;
    struct book_node *next;
} nodes;

typedef struct headnode{
    char head[32];
    nodes *next;
    struct headnode *down;
} heads;

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

heads *creathead(void){
    heads *tmp=NULL;
    tmp=(heads *)malloc(sizeof(heads));
    if(NULL==tmp){
        printf("head malloc ERR");
    }
    memset(tmp,0,sizeof(tmp));
    return tmp;
}

bookinfs *makebookinf(void){
    bookinfs *newinf=NULL;
    newinf=creatbookinf();
    printf("录入时，请依次输入：\n书名 作者名 页数 价格 出版年 ISBN\n");
    scanf("%s%s%d%f%d%d",newinf->bookname,newinf->author,&newinf->page,&newinf->price,&newinf->year,&newinf->ISBN);
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

heads *makelink(heads *headnode,nodes *new){
    heads *tmphead=NULL;
    tmphead=creathead();
    nodes *tmpnode=NULL;
    tmpnode=creatnode();
    tmpnode=new;
    tmphead=headnode;
    tmpnode->next=tmphead->next;
    tmphead->next=tmpnode;
    return tmphead;
}

heads *makehead(heads *headnode,nodes *new){
    heads *tmp=NULL;
    tmp=creathead();
    strcpy(tmp->head,new->inf->author);
    return tmp;
}

heads *makehashtable(heads *booktable,nodes *new){
    int flag=1;
    heads *tmphead=NULL;
    tmphead=creathead();
    tmphead=booktable;
    
    while(NULL!=tmphead->down){
        if(0==strcmp(new->inf->author,tmphead->head)){
            tmphead=makelink(tmphead,new);
            flag=0;
            break;
        }
        tmphead=tmphead->down; 
    }
    if(0==strcmp(new->inf->author,tmphead->head)){
        tmphead=makelink(tmphead,new);
        flag=0;
    }
    if(1==flag){
        heads *newhead=NULL;
        newhead=creathead();
        newhead=makehead(tmphead,new);
        tmphead->down=newhead;
        tmphead=makelink(tmphead,new);
    }
    puts("A");
    printf("%p",tmphead->next);
}

void load_data(heads *headnode,FILE *fp){
    
    while(0==feof(fp)){
        nodes *newnode=NULL;
        newnode=creatnode();
        bookinfs *newinf;
        newinf=creatbookinf();
        newnode->inf=newinf;
        char bookname[32],author[32];
        float price;
        int page,ISBN,year;
        fscanf(fp,"%s%s%d%f%d%d",bookname,author,&page,&price,&year,&ISBN);
        strcpy(newinf->bookname,bookname);
        strcpy(newinf->author,author);
        newinf->page=page;
        newinf->price=price;
        newinf->year=year;
        newinf->ISBN=ISBN;
        headnode=makehashtable(headnode,newnode);
    }
    return ;
}

void write_data(heads *headnode,FILE *fp){
    
    heads *tmphead=NULL;
    tmphead=headnode;
    nodes *tmpnode;
    while(NULL!=tmphead->down){
        tmpnode=headnode->next;
        while(NULL!=tmpnode){
            fprintf(fp,"%s%s%d%f%d%d",tmpnode->inf->bookname,tmpnode->inf->author,tmpnode->inf->page,tmpnode->inf->price,tmpnode->inf->year,tmpnode->inf->ISBN);
            tmpnode=tmpnode->next;
        }
        tmphead=tmphead->down;
    }
    return ;
}

void list(heads *headnode){
    
    if(NULL==headnode->down){
        printf("NO ONE BOOK!");
        return ;
    }
    heads *tmphead=headnode->down;
    nodes *tmpnode=NULL;
    tmpnode=creatnode();
    printf("%s",tmphead->down->head);
    while(NULL!=tmphead->down){
        tmpnode=tmphead->next;
        while(NULL!=tmpnode->next){
            printf("%s%s%d%f%d%d",tmpnode->inf->bookname,tmpnode->inf->author,tmpnode->inf->page,tmpnode->inf->price,tmpnode->inf->year,tmpnode->inf->ISBN);
            tmpnode=tmpnode->next;
        }
        printf("%s%s%d%f%d%d",tmpnode->inf->bookname,tmpnode->inf->author,tmpnode->inf->page,tmpnode->inf->price,tmpnode->inf->year,tmpnode->inf->ISBN);
        tmphead=tmphead->down;
    }
    while(NULL!=tmpnode->next){
        printf("%s%s%d%f%d%d",tmpnode->inf->bookname,tmpnode->inf->author,tmpnode->inf->page,tmpnode->inf->price,tmpnode->inf->year,tmpnode->inf->ISBN);
        tmpnode=tmpnode->next;
    }
    printf("%s%s%d%f%d%d",tmpnode->inf->bookname,tmpnode->inf->author,tmpnode->inf->page,tmpnode->inf->price,tmpnode->inf->year,tmpnode->inf->ISBN);
}

int main(int argc,char *argv[]){
    heads *headmain=NULL;
    headmain=creathead();
    int select,flag=1;
    FILE *fp=NULL;
    
    //fp=fopen(argv[1],"rw");  
    //load_data(headmain,fp);
    
    while(flag){
        scanf("%d",&select);
        switch(select){
        case 1:
            nodes *newnode;
            newnode=creatnode();
            newnode=makenode();
            makehashtable(headmain,newnode);
            printf("%s",headmain->down->next->inf->bookname);
            //printf("%s",headmain->down->down->head);
            //write_data(headmain,fp);
            //list(headmain);
            break;
        case 2:
            list(headmain);
        default:
            flag=0;
            break;
        }
    }

    fclose(fp);

    return 0;
}