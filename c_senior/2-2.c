#include<stdio.h>

typedef struct stu{
    char name[20];
    int age;
} s;

typedef struct peo{
    int id;
    s stus;
} p;


int main(){
    p c1;
    p *cp=&c1;
    scanf("%d%s%d",&cp->id,cp->stus.name,&cp->stus.age);
    printf("%d %s %d\n",cp->id,cp->stus.name,cp->stus.age);
}
