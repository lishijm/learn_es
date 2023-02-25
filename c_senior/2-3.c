#include<stdio.h>

typedef struct{
    char name[20];
    int age;
} s;

typedef struct{
    int id;
    s *sp;
} p;


int main(){
    p pi;
    p *pp=&pi;
    s si;
    pp->sp=&si;
    scanf("%d%s%d",&pp->id,pp->sp->name,&pp->sp->age);
    printf("%d %s %d\n",pp->id,pp->sp->name,pp->sp->age);
}