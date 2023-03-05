#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
 
 
struct book
{
	int number;      //图书编号 
	char name[85];   //图书名称 
	char writer[85]; //图书作者 
	char type[85];   //图书类别 
	int price;       //图书价格  
	struct book *next;
};
struct node
{
	struct book data;
	struct node *next;
};
struct node *head=NULL;
 
 
void welcome();
void createHeadNode();
void add_book(struct node *head);
void delete_book(struct node *find);
void sum_book(struct node *head);
void init_data(struct node *head);
void statistics_book(struct node *head);
struct node *find_book(struct node *head,int number);
struct node *find1_book(struct node *head,char name[85]);
void search_book(struct node *head); 
void search1_book(struct node *head); 
void search2_book(struct node *head); 
void change_book(struct node *head); 
void sort_book(struct node *head);
void sort1_book(struct node *head); 
void sort2_book(struct node *head);
void show_book(struct node *head);
void info_output(struct node *find);
void keep_book(struct node *head);
 
 
 
int count; 
int main()
{
	createHeadNode();
    welcome();
    system("pause");
	return 0;
} 
 
 
void welcome()
{
	int a=0;
    init_data(head);
    printf("当前有%d条数据!\n",count); 
	printf("***************************************\n");
	printf("***************************************\n");
	printf("*         欢迎使用图书管理系统        *\n");
	printf("***************************************\n");
	printf("***************************************\n");
	printf("*         请输入您要进行的操作        *\n");
	printf("***************************************\n");
    printf("*              1.添加图书             *\n");
    printf("*              2.删除图书             *\n");    
	printf("*              3.保存图书             *\n");
    printf("*              4.图书列表             *\n");
    printf("*              5.修改图书             *\n");
    printf("*              6.查找图书             *\n");
    printf("*              7.图书排序             *\n");
    printf("*              8.图书统计             *\n");
    printf("*              0.退出系统             *\n");	
	printf("***************************************\n");
	printf("***************************************\n");
	printf("请输入您需要进行的操作，并且按Enter进入！\n");
	while(1)
	{
		scanf("%d",&a);
		switch(a)
		{
			case 1://1.添加图书
				add_book(head);
				break;
			case 2://2.删除图书
				delete_book(head);
				break;
			case 3://3.保存图书
				keep_book(head);
				break;
			case 4://4.图书列表  
				show_book(head);
				break;
			case 5://5.修改图书
				change_book(head);
				break;
			case 6://6.查找图书
				search_book(head);
				break;
			case 7://7.图书排序 
				sort_book(head);
				break;
			case 8://8.图书排序 
			    statistics_book(head);
				break;
			case 0://0.退出系统
			    exit(0);																							
		} 
		printf("请输入您需要进行的操作！\n");
	} 
					
}
 
void createHeadNode()
{
	head=(struct node *)malloc(sizeof(struct node));
	if(!head)
	{
		printf("头结点分配失败！\n");
		return;
	}
	head->next=NULL;
}
 
void add_book(struct node *head)
{
	struct node *new=NULL;
	struct node *find=head;
	while(find->next!=NULL)
	{
		find=find->next;
	}
	new=(struct node *)malloc(sizeof(struct node));
	printf("请输入图书编号：\n");
	scanf("%d",&new->data.number);
	printf("请输入图书名称：\n");
	scanf("%s",new->data.name);
	printf("请输入图书作者：\n");
	scanf("%s",new->data.writer);
	printf("请输入图书类别：\n");
	scanf("%s",new->data.type);
	printf("请输入图书价格：\n");
	scanf("%d",&new->data.price);
	new->next=NULL;
	find->next=new;
	printf("%s图书信息添加成功！\n",new->data.name);
	printf("\n");
}
 
void show_book(struct node *head)
{
	struct node *find=head->next;
	while(find!=NULL)
	{
		info_output(find);
		find=find->next;
	}
}
 
void info_output(struct node *find)
{
 
	printf("----------------------------------------------------------------------------\n");
	printf(" 编号：%d\t 名称：%s\t 作者：%s\t 类别：%s\t 价格：%d\t \n",find->data.number,find->data.name,find->data.writer,find->data.type,find->data.price);
	printf("----------------------------------------------------------------------------\n");
}
 
void delete_book(struct node *head)
{
	int m=0;
	struct node *target=NULL;
	struct node *find=head;
	struct node *temp=NULL;
	printf("请输入您需要删除图书的编号： \n");
	scanf("%d",&m);
	target=find_book(head,m);
	if(target==NULL)
	{
		printf("该图书不存在！\n");
		return;
	}
	else
	{
		temp=target->next;
		while(find->next!=target)
		{
			find=find->next;
		}
		free(target);
		target=NULL;
		find->next=temp;
		printf("删除成功！\n");
	}
}
 
 
struct node *find_book(struct node *head,int number)
{
	struct node *find=head;
	while(find!=NULL)
	{
		if(find->data.number==number)
		{
			return find;
		}
		find=find->next;
	}
	return find;
}
 
void search1_book(struct node *head)
{
	int n=0;
	struct node *target=NULL;
	printf("请输入您需要查找的图书编号：\n");
	scanf("%d",&n);
	target=find_book(head,n);
	if(target==NULL)
	{
		printf("该图书不存在！\n");
	}
	else
	{
		info_output(target);
	}
}
 
 
struct node *find1_book(struct node *head,char *bname)
{
	struct node *find=head;
	while(find!=NULL)
	{
        if(strcmp(find->data.name,bname)==0)
		{
			return find;
		}
		find=find->next;
	}
	return find;
 
}
 
void search2_book(struct node *head)
{
	char bname[85];
	struct node *target=NULL;
	printf("请输入您需要查找的图书名称：\n");
	scanf("%s",bname);
	target=find1_book(head,bname);
	if(target==NULL)
	{
		printf("该图书不存在！\n");
	}
	else
	{
		info_output(target);
	}
}
 
 
void search_book(struct node *head)
{
	int n;
	printf("************************************\n");
	printf("************************************\n");
	printf("     请输入您需要操作的查找方式：   \n");
	printf("************************************\n");
	printf("************************************\n");
	printf("*         1.按图书编号查找         *\n");
	printf("*         2.按图书名称查找         *\n");
	printf("************************************\n");
	printf("************************************\n");
	scanf("%d",&n);
	switch(n)
	{
		case 1:
			search1_book(head);
			break;
		case 2:
			search2_book(head);
			break;
	} 
}
 
 
void change_book(struct node *head)
{
	int n=0;
	struct node *target=NULL;
	printf("请输入您需要修改的图书编号：\n");
	scanf("%d",&n);
	target=find_book(head,n);
	if(target==NULL)
	{
		printf("该图书不存在！\n");
	}
	else
	{
		printf("请输入图书编号：\n");\
        scanf("%d",&target->data.number);
	    printf("请输入图书名称：\n");
	    scanf("%s",target->data.name);
	    printf("请输入图书作者：\n");
	    scanf("%s",target->data.writer);
	    printf("请输入图书类别：\n");
    	scanf("%s",target->data.type);
    	printf("请输入图书价格：\n");
    	scanf("%d",&target->data.price);
    	printf("图书信息修改成功！\n");
    	info_output(target);
	}
}
 
 
void sort1_book(struct node *head)
{
	struct node *find1=head;
	struct node *find2=head;
    struct book t;
	for(find1=head->next;find1!=NULL;)
	{
		for(find2=find1->next;find2!=NULL;)
		{
			if(find1->data.number>find2->data.number)
			{
				t=find1->data;
				find1->data=find2->data;
				find2->data=t;
			}
			else
		    	break;
		    	find2=find2->next;
		}
		find1=find1->next;
	 } 
	 printf("排序完成！\n");
	 show_book(head);
}
 
 
void sort2_book(struct node *head)
{
	struct node *find1=head;
	struct node *find2=head;
    struct book t;
	for(find1=head->next;find1!=NULL;)
	{
		for(find2=find1->next;find2!=NULL;)
		{
			if(find1->data.price<find2->data.price)
			{
				t=find1->data;
				find1->data=find2->data;
				find2->data=t;
			}
			else
		    	break;
		    	find2=find2->next;
		}
		find1=find1->next;
	 } 
	 printf("排序完成！\n");
	 show_book(head);
}
 
 
 
void sort3_book(struct node *head)
{
	struct node *find1=head;
	struct node *find2=head;
    struct book t;
	for(find1=head->next;find1!=NULL;)
	{
		for(find2=find1->next;find2!=NULL;)
		{
			if(find1->data.price>find2->data.price)
			{
				t=find1->data;
				find1->data=find2->data;
				find2->data=t;
			}
			else
		    	break;
		    	find2=find2->next;
		}
		find1=find1->next;
	 } 
	 printf("排序完成！\n");
	 show_book(head);
}
 
void Sort_book(struct node *head)
{
	int n;
	printf("************************************\n");
	printf("************************************\n");
	printf("     请输入您需要价格排序方式：   \n");
	printf("************************************\n");
	printf("************************************\n");
	printf("*            1.价格降序            *\n");
	printf("*            2.价格升序            *\n");
	printf("************************************\n");
	printf("************************************\n");
	scanf("%d",&n);
	switch(n)
	{
		case 1:
			sort2_book(head);
			break;
		case 2:
			sort3_book(head);
			break;
	} 
}
 
void sort_book(struct node *head)
{
	int n;
	printf("************************************\n");
	printf("************************************\n");
	printf("     请输入您需要操作的排序方式：   \n");
	printf("************************************\n");
	printf("************************************\n");
	printf("*         1.按图书编号排序         *\n");
	printf("*         2.按图书价格排序         *\n");
	printf("************************************\n");
	printf("************************************\n");
	scanf("%d",&n);
	switch(n)
	{
		case 1:
			sort1_book(head);
			break;
		case 2:
			Sort_book(head);
			break;
	} 
}
 
 
void init_data(struct node *head)
{
	FILE *fp=NULL;
	struct node *new=NULL;
	struct node *find=head;
	fp=fopen("book.txt","r");
	if(!fp)
	{
		printf("文件打开失败！\n");
		exit(0);
	}
	while(1)
	{
		new=(struct node *)malloc(sizeof(struct node));
		fscanf(fp,"%d%s%s%s%d",&new->data.number,new->data.name,new->data.writer,new->data.type,&new->data.price);
		new->next=NULL;
		if(feof(fp))
		{
			break;
		}
		count++;
		find->next=new;
		find=find->next;
	}
}
 
 
void keep_book(struct node *head)
{
	FILE *fp=NULL;
	struct node *find=head->next;
	fp=fopen("book.txt","w");
	while(find!=NULL)
	{
		fprintf(fp,"图书编号：%d\t图书名称：%s\t图书作者：%s\t图书类别：%s\t图书价格：%d\n",find->data.number,find->data.name,find->data.writer,find->data.type,find->data.price);
		find=find->next;
	}
	printf("数据保存成功！\n");
}
 
void sum_book(struct node *head)
{
	int cnt;
	cnt=0;
	struct node *move=head; 
	while(NULL!=move->next)
	{
		move=move->next;
		cnt++;
	}
	printf("当前管理系统有%d本图书！\n",cnt);
    printf("\n"); 
 } 
 
 
 void statistics_book(struct node *head)
 {
	printf("************************************\n");
	printf("       请输入您需要的统计方式：     \n");
	printf("************************************\n");
	printf("*         1.整体统计               *\n");
	printf("*         2.按图书作者统计         *\n");
	printf("*         3.按图书类别统计         *\n");
	printf("************************************\n");
	int n;
	scanf("%d",&n);
	int c=0;
	char writer[85];
	char type[85];
	struct node *find1=head;
	struct node *find2=head;
	switch(n)
	{
		case 1:
		    sum_book(head);
		    break;
		case 2:
			printf("请输入您要统计图书的作者：\n");
			scanf("%s",writer);
			while(find1)
			{
				if(strcmp(find1->data.writer,writer)==0)
				{
					printf("图书编号：%d\t图书名称：%s\t图书作者：%s\t图书类别：%s\t图书价格：%d\t\n",find1->data.number,find1->data.name,find1->data.writer,find1->data.type,find1->data.price);
					c++;
				}
				find1=find1->next;
			}
			if(c==0)
			printf("未找到%s所著图书！\n",writer);
			else
			printf("共有%d本%s所著图书！\n",c,writer);
			printf("\n");
			break;
		case 3:
			printf("请输入您要统计图书的类别：\n");
			scanf("%s",type);
			while(find1)
			{
				if(strcmp(find1->data.type,type)==0)
				{
					printf("图书编号：%d\t图书名称：%s\t图书作者：%s\t图书类别：%s\t图书价格：%d\t\n",find1->data.number,find1->data.name,find1->data.writer,find1->data.type,find1->data.price);
					c++;
				}
				find1=find1->next;
			}
			if(c==0){
			printf("未找到%s类别的图书！\n",type);
			printf("\n");}
			else{
			printf("共有%d本%s类别的图书！\n",c,type);
			printf("\n");}
						break;
	 } 
 
 }