#include<stdio.h>

typedef struct{
    char name[20];
    int age;
} s;

typedef struct{
    int id;
    s stu;
} p;


int main(){
    p pi;
    p *pp=&pi;
    s *sp;
    sp=&pp->stu;
    scanf("%d%s%d",&pp->id,sp->name,&sp->age);
    printf("%d %s %d\n",pp->id,sp->name,sp->age);
}