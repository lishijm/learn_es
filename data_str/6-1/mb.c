#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

typedef struct book{
    char bookname[32],author[32];
    float price;
    int page,ISBN,kind;
} infs;

typedef struct linksnode{
    infs *inf;
    struct linksnode *next;
} links;

infs *creainf(void){
    infs *ninf=NULL;
    ninf=(infs *)malloc(sizeof(infs));
    memset(ninf,0,sizeof(infs));
    return ninf;
}

links *creanode(void){
    links *plinks=NULL;
    plinks=(links *)malloc(sizeof(links));
    memset(plinks,0,sizeof(links));
    return plinks;
}

infs *makeinf(void){
    infs *newinf=NULL;
    newinf=creainf();
    printf("录入时，请依次输入,输入完毕请按Enter键。\n书名 作者名 页数 价格 书柜号 ISBN\n");
    scanf("%s%s%d%f%d%d",newinf->bookname,newinf->author,&newinf->page,&newinf->price,&newinf->kind,&newinf->ISBN);
    return newinf;
}

links *makenode(){
    links *newnode=NULL;
    newnode=creanode();
    infs *newinf=NULL;
    newinf=makeinf();
    newnode->inf=newinf;

    return newnode;
}

links* makehashlinks(links *block[],links *new,int legnth){
    links *tmp=NULL;
    int in;
    in=(new->inf->kind)-1;
    tmp=block[in];
    new->next=tmp->next;
    tmp->next=new;
}

void list(links *block[],int legnth){
    int i;
    links *tmp=NULL;
    printf("书库在库图书列表：\n");
    for(i=0;i<legnth;i++){
        tmp=block[i];
        while(tmp->next!=NULL){
            printf("书名：%s 作者：%s 页数：%d 价格：%.2f 书柜号：%d ISBN：%d\n",tmp->next->inf->bookname,tmp->next->inf->author,tmp->next->inf->page,tmp->next->inf->price,tmp->next->inf->kind,tmp->next->inf->ISBN);
            tmp=tmp->next;
        }
    }
}

links *search(links *block[],int legnth,char find[32]){
    int i=0,flag=1;
    links *tmp=NULL;
    tmp=creanode();
    for (i=0;i<legnth;i++){
        tmp=block[i];
        while(tmp->next!=NULL){
            if(0==strcmp(tmp->next->inf->bookname,find)){
                printf("在第%d号书柜\n",i+1);
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
        printf("书库中没有此图书，请查看外借图书列表。\n");
        
        return NULL;
    }

    return tmp;
}

void menuchange(void){
    printf("作者******************1\n");
    printf("页数******************2\n");
    printf("价格******************3\n");
    printf("书柜号****************4\n");
    printf("***********************\n");
}

void cauth(links *tmp,char change[32]){
    strcpy(tmp->inf->author,change);
}

void cpage(links *tmp,int change){
    tmp->inf->page=change;
}

void cprice(links *tmp,float change){
    tmp->inf->price=change;
}

void ckind(links *pre,int change,links *block[]){
    links *changenode=pre->next;
    pre->next=changenode->next;
    changenode->next=block[change-1]->next;
    block[change-1]->next=changenode;
    changenode->inf->kind=change;
}

void change(links *block[],int legnth){
    printf("输入你需要更改的图书书名\n");
    char change_book[32];
    scanf("%s",change_book);
    links *tmp=NULL;
    tmp=search(block,legnth,change_book);
    if(NULL==tmp){
        return ;
    }
    int selc;
    printf("选择你需要更改的信息\n");
    menuchange();
    scanf("%d",&selc);
    switch(selc){
    case 1:
        printf("请输入作者名：\n");
        char change_author[32];
        scanf("%s",change_author);
        cauth(tmp->next,change_author);
        break;
    case 2:
        printf("请输入页数：\n");
        int change_page;
        scanf("%d",&change_page);
        cpage(tmp->next,change_page);
        break;
    case 3:
        printf("请输入价格：\n");
        float change_price;
        scanf("%f",&change_price);
        cprice(tmp->next,change_price);
        break;
    case 4:
        printf("请输入书柜号：\n");
        int change_kind;
        scanf("%d",&change_kind);
        ckind(tmp,change_kind,block);
        break;
    default:
        break;
    }
}

void del(links *block[],links *delhead,int legnth){
    printf("请输入借出的图书书名：\n");
    char del_book[32];
    scanf("%s",del_book);
    links *tmp=NULL;
    tmp=search(block,legnth,del_book);
    if(NULL==tmp){
        return ;
    }
    links *delnode;
    delnode=tmp->next;
    if(NULL!=delnode->next){
        tmp->next=delnode->next;
    }
    else{
        tmp->next=NULL;
    }
    delnode->next=NULL;
    delhead->next=delnode;
    printf("%s已经被借出。\n",del_book);
}

void delprint(links *delhead){
    printf("外借图书列表:\n");
    while(NULL!=delhead->next){
        printf("书名：%s 作者：%s 页数：%d 价格：%.2f 书柜号：%d ISBN：%d\n",delhead->next->inf->bookname,delhead->next->inf->author,delhead->next->inf->page,delhead->next->inf->price,delhead->next->inf->kind,delhead->next->inf->ISBN);
        delhead=delhead->next;
    }
}

void re(links *block[],links *delhead,int legnth){
    printf("请输入归还的图书书名；\n");
    char rname[32];
    scanf("%s",rname);
    links *tmp=delhead;
    while(NULL!=delhead->next){
        if(0==strcmp(tmp->next->inf->bookname,rname)){
            break;
        }
    }
    makehashlinks(block,tmp->next,legnth);
    if(NULL!=tmp->next->next){
        tmp->next=tmp->next->next;
    }
    else{
        tmp->next=NULL;
    }
    printf("图书已归还\n");
}

void dels(links *block[],int legnth){
    links *tmp,*delnode;
    infs *delinf;
    printf("请输入销毁的图书书名:\n");
    char destroyname[32];
    scanf("%s",destroyname);
    tmp=search(block,legnth,destroyname);
    if(NULL==tmp){
        return ;
    }
    delnode=tmp->next;
    delinf=tmp->next->inf;
    if(NULL!=tmp->next->next){
        tmp->next=tmp->next->next;
    }
    else{
        tmp->next=NULL;
    }
    free(delinf);
    free(delnode);
    printf("图书已经销毁\n");
}

void destroy_hash(links *block[],int legnth){
    links *delnode,*tmp;
    infs *delinf;
    int i;
    for(i=0;i<legnth;i++){
        tmp=block[i];
        while(NULL!=tmp->next){
            delnode=tmp;
            delinf=tmp->inf;
            tmp=tmp->next;
            free(delnode);
            free(delinf);
        }
        delnode=tmp;
        delinf=tmp->inf;
        free(delnode);
        free(delinf);
    }
}

void destroy_bow(links *delhead){
    links *delnode,*tmp;
    infs *delinf;
    tmp=delhead;
    while(NULL!=tmp->next){
        delnode=tmp;
        delinf=tmp->inf;
        tmp=tmp->next;
        free(delnode);
        free(delinf);
    }
    delnode=tmp;
    delinf=tmp->inf;
    free(delnode);
    free(delinf);
}

void write_libdata(links *block[],int legnth){
    links *tmp=NULL;
    infs bookinf;
    int fwlib=open("libdata",O_WRONLY|O_CREAT|O_TRUNC,0644);
    if(fwlib<0){
        perror("open error");
    }
    else{
        int i;
        for(i=0;i<legnth;i++){
            tmp=block[i];
            while(NULL!=tmp->next){
                strcpy(bookinf.author,tmp->next->inf->author);
                strcpy(bookinf.bookname,tmp->next->inf->bookname);
                bookinf.page=tmp->next->inf->page;
                bookinf.price=tmp->next->inf->price;
                bookinf.kind=tmp->next->inf->kind;
                bookinf.ISBN=tmp->next->inf->ISBN;
                int wr_count=write(fwlib,&bookinf,sizeof(infs));
                if(0==wr_count){
                    printf("未写入成功\n");
                }
                else if(wr_count<0){
                    perror("写入失败\n");
                    break;
                }
                tmp=tmp->next;
            }
        }
    }
    close(fwlib);
}

void write_bowdata(links *delhead){
    links *tmp=delhead;
    infs bookinf;
    int fwbow=open("bowdata",O_WRONLY|O_CREAT|O_TRUNC,0644);
    if(fwbow<0){
        perror("open error");
    }
    else{
        while(NULL!=tmp->next){
            strcpy(bookinf.author,tmp->next->inf->author);
            strcpy(bookinf.bookname,tmp->next->inf->bookname);
            bookinf.page=tmp->next->inf->page;
            bookinf.price=tmp->next->inf->price;
            bookinf.kind=tmp->next->inf->kind;
            bookinf.ISBN=tmp->next->inf->ISBN;
            int wr_count=write(fwbow,&bookinf,sizeof(infs));
            if(0==wr_count){
                printf("未写入成功\n");
            }
            else if(wr_count<0){
                printf("写入失败\n");
                break;
            }
            tmp=tmp->next;
        }
        
    }
    close(fwbow);
}

void read_libdata(links *block[],int legnth){
    int frlib=open("libdata",O_RDONLY);
    infs tmpinf;
    if(frlib<0){
        perror("open error");
    }
    else{
        while(1){
            int rd_count=read(frlib,&tmpinf,sizeof(infs));
            if(0==rd_count){
                printf("书库信息导入完成\n");
                break;
            }
            else if(rd_count<0){
                perror("书库导入失败\n");
            }
            else{
                infs *ptmpinf=NULL;
                ptmpinf=creainf();
                strcpy(ptmpinf->bookname,tmpinf.bookname);
                strcpy(ptmpinf->author,tmpinf.author);
                ptmpinf->page=tmpinf.page;
                ptmpinf->price=tmpinf.price;
                ptmpinf->kind=tmpinf.kind;
                ptmpinf->ISBN=tmpinf.ISBN;
                links *new=NULL;
                new=creanode();
                new->inf=ptmpinf;
                makehashlinks(block,new,legnth);
            }
        }
    }
    close(frlib);
}

void read_bowdata(links *delhead){
    int frlib=open("bowdata",O_RDONLY);
    infs tmpinf;
    if(frlib<0){
        perror("open error");
    }
    else{
        while(1){
            int rd_count=read(frlib,&tmpinf,sizeof(infs));
            if(0==rd_count){
                printf("外借信息信息导入完成\n");
                break;
            }
            else if(rd_count<0){
                perror("外借导入失败\n");
            }
            else{
                infs *ptmpinf=NULL;
                ptmpinf=creainf();
                strcpy(ptmpinf->bookname,tmpinf.bookname);
                strcpy(ptmpinf->author,tmpinf.author);
                ptmpinf->page=tmpinf.page;
                ptmpinf->price=tmpinf.price;
                ptmpinf->kind=tmpinf.kind;
                ptmpinf->ISBN=tmpinf.ISBN;
                links *new=NULL;
                new=creanode();
                new->inf=ptmpinf;
                new->next=delhead->next;
                delhead->next=new;
            }
        }
    }
    close(frlib);
}

void mainmenu(void){
    system("clear");
    printf("***********************\n");
    printf("****               ****\n");
    printf("****  图书管理系统 ****\n");
    printf("****               ****\n");
    printf("***********************\n");
    printf("录入信息**************1\n");
    printf("在库图书列表**********2\n");
    printf("查询在库图书**********3\n");
    printf("修改在库图书信息******4\n");
    printf("办理图书外借**********5\n");
    printf("外借图书列表**********6\n");
    printf("办理图书归还**********7\n");
    printf("销毁图书**************8\n");
    //printf("按顺序查看在库图书****9\n");
    printf("保存所有更改**********0\n");
    printf("退出系统*************99\n");
    printf("***********************\n");
}

void menukind(void){
    printf("***********************\n");
    printf("*                     *\n");
    printf("以下为每种图书对应书柜号\n");
    printf("*                     *\n");
    printf("***********************\n");
    printf("马列毛****************1\n");
    printf("哲学******************2\n");
    printf("社会科学**************3\n");
    printf("自然科学**************4\n");
    printf("综合性图书************5\n");
    printf("***********************\n");
}

int main(){
    int i,legnth=5,sel,flag=1;
    links *block[legnth],*delhead;
    for(i=0;i<legnth;i++){
        block[i]=NULL;
        block[i]=creanode();
    }
    delhead=NULL;
    delhead=creanode();
    
    read_libdata(block,legnth);
    read_bowdata(delhead);
    printf("按Enter进入图书管理系统\n");
    getchar();

    while(flag){
        mainmenu();
        scanf("%d",&sel);
        switch (sel){
        case 1:
            system("clear");
            menukind();
            links *new=NULL;
            new=creanode();
            new=makenode();
            makehashlinks(block,new,legnth);
            printf("按Enter返回菜单\n");
            getchar();
            getchar();
            break;
        case 2:
            system("clear");
            list(block,legnth);
            printf("按Enter返回菜单\n");
            getchar();
            getchar();
            break;
        case 3:
            system("clear");
            printf("请输入所查询图书书名\n");
            char find[32];
            scanf("%s",find);
            search(block,legnth,find);
            printf("按Enter返回菜单\n");
            getchar();
            getchar();
            break;
        case 4:
            system("clear");
            change(block,legnth);
            printf("按Enter返回菜单\n");
            getchar();
            getchar();
            break;
        case 5:
            system("clear");
            del(block,delhead,legnth);
            printf("按Enter返回菜单\n");
            getchar();
            getchar();
            break;
        case 6:
            system("clear");
            delprint(delhead);
            printf("按Enter返回菜单\n");
            getchar();
            getchar();
            break;
        case 7:
            system("clear");
            re(block,delhead,legnth);
            printf("按Enter返回菜单\n");
            getchar();
            getchar();
            break;
        case 8:
            system("clear");
            dels(block,legnth);
            printf("按Enter返回菜单\n");
            getchar();
            getchar();
            break;
        /*case 9:
            system("clear");
            printf("目前仅支持价格排序\n");
            sort(block,legnth,);
            break;
        */
        case 0:
            system("clear");
            write_libdata(block,legnth);
            write_bowdata(delhead);
            printf("保存成功！\n");
            printf("按任意键+Enter返回菜单\n");
            getchar();
            getchar();
            break;
        case 99:
            system("clear");
            flag=0;
            break;
        }
    }
    destroy_hash(block,legnth);
    destroy_bow(delhead);

    return 0;
}