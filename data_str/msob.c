#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct date{
    int year,month;
} dates;

typedef struct ISBN{
    int group,title,check;
} ISBNs;

typedef struct book_information{
    char bookname[32],author[32],layout[8];
    dates *date;
    ISBNs *ISBN;
    float price;
    int page;
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

dates *creatdate(void){
    dates *tmp=NULL;
    tmp=(dates *)malloc(sizeof(dates));
    if(NULL==tmp){
        puts("date malloc ERR");
    }
    memset(tmp,0,sizeof(tmp));
    return tmp;
}

ISBNs *creatISBN(void){
    ISBNs *tmp=NULL;
    tmp=(ISBNs *)malloc(sizeof(ISBNs));
    if(NULL==tmp){
        puts("ISBN malloc ERR");
    }
    memset(tmp,0,sizeof(tmp));
    return tmp;
}

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

dates *makebookdate(void){
    dates *newdate=NULL;
    newdate=creatdate();
    scanf("%d%d",&newdate->year,&newdate->month);

    return newdate;
}

ISBNs *makebookISBN(void){
    ISBNs *newISBN=NULL;
    newISBN=creatISBN();
    printf("请输入书籍的ISBN码\n国家/语言代码 出版商代码 书号 检查码\n");
    scanf("%d%d%d",&newISBN->group,&newISBN->title,&newISBN->check);

    return newISBN;
}

bookinfs *makebookinf(void){
    bookinfs *newinf=NULL;
    newinf=creatbookinf();
    printf("录入时，请依次输入：\n书名 作者名 页数 价格 出版年 出版月\n");
    scanf("%s%s",newinf->bookname,newinf->author,newinf->page,newinf->price);
    
    dates *newdate=NULL;
    newdate=makebookdate();
    ISBNs *newISBN=NULL;
    newISBN=makebookISBN();
    
    newinf->date=newdate;
    newinf->ISBN=newISBN;

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

heads *makelink(heads *headnode,){
    
}

heads* makehashtable(heads *booktable,nodes *new){
    while(NULL==booktable->down){
        if(new->inf->author==booktable->head){
            makelink(booktable);
            break;
        }
        else{

        }
        booktable=booktable->down;
    }
    char author_code;
    author_code=new->inf->author;
}

int main(){
    heads *headmain=NULL;
    headmain=creathead();
    

    return 0;
}