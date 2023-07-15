#include<stdio.h>

typedef struct stu{
    char name[20];
    int age;
} s;

int main(){
    s class1;
    s *cc=&class1;
    scanf("%s%d",cc->name,&cc->age);
    printf("%s %d",cc->name,cc->age);
}
