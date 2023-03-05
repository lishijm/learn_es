#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct date{
    int year,month;
} dates;

typedef struct ISBN{
    int state,publisher,title,check;
} ISBNs;

typedef struct book_information{
    char bookname[32],author[32];
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
    scanf("%d%d%d%d",&newISBN->state,&newISBN->publisher,&newISBN->title,&newISBN->check);

    return newISBN;
}

bookinfs *makebookinf(void){
    bookinfs *newinf=NULL;
    newinf=creatbookinf();
    printf("录入时，请依次输入：\n书名 作者名 页数 价格 出版年 出版月\n");
    scanf("%s%s%d%f",newinf->bookname,newinf->author,&newinf->page,&newinf->price);
    
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

void makelink(heads *headnode,nodes *new,FILE *fp){
    new->next=headnode->next;
    headnode->next=new;
    fwrite(new,sizeof(new),1,fp);
}

heads *makehead(heads *headnode,nodes *new){
    heads *tmp=NULL;
    tmp=creathead();
    strcpy(tmp->head,new->inf->author);
    return tmp;
}

heads* makehashtable(heads *booktable,nodes *new,FILE *fp){
    heads *fheadbuffer=NULL;
    fheadbuffer=creathead();
    int flag=1;
    //while(0==feof(fp)){
        fread(fheadbuffer, sizeof(heads), 1, fp);
        booktable=fheadbuffer;
        if(new->inf->author==booktable->head){
            makelink(booktable,new,fp);
            flag=0;
            //break;
        }
        if(1==flag){
            heads *newhead=NULL;
            newhead=creathead();
            newhead=makehead(booktable,new);
            booktable->down=newhead;
            booktable=newhead;
            makelink(booktable,new,fp);
        }
    //}
}

int main(int argc,char *argv[]){
    heads *headmain=NULL;
    headmain=creathead();
    int select,flag=1;
    
    FILE *fp;
    
    while(flag){
        scanf("%d",&select);
        switch(select){
        case 1:
            fp=fopen(argv[1],"r+b");
            nodes *newnode;
            newnode=creatnode();
            newnode=makenode();
            makehashtable(headmain,newnode,fp);
            break;
        default:
            flag=0;
            break;
        }
    }


    return 0;
}