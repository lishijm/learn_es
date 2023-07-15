#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student{
    char name[20];
    int age;
    int mark[3];
} stu;

void nsize(stu (*p)[3]){
    int i,j;
    stu tmp;

    for(i=0;i<3;i++){
        for(j=0;j<3-i-1;j++){
            if((strcmp((((*p)+j)->name),(((*p)+j+1)->name)))>0){
                tmp=*((*p)+j+1);
                *((*p)+j+1)=*((*p)+j);
                *((*p)+j)=tmp;
            }
        }
    }
}

void age(stu (*p)[3]){
    int i,j;
    stu tmp;

    for(i=0;i<3;i++){
        for(j=0;j<3-i-1;j++){
            if(((*p)+j)->age>((*p)+j+1)->age){
                tmp=*((*p)+j+1);
                *((*p)+j+1)=*((*p)+j);
                *((*p)+j)=tmp;
            }
        }
    }
}

void mark(stu (*p)[3],int s){
    int i,j;
    stu tmp;

    for(i=0;i<3;i++){
        for(j=0;j<3-i-1;j++){
            if(((*p)+j)->mark[s]<((*p)+j+1)->mark[s]){
                tmp=*((*p)+j+1);
                *((*p)+j+1)=*((*p)+j);
                *((*p)+j)=tmp;
            }
        }
    }
}

void avr(stu (*p)[3],int s){
    int i;
    float sum=0;

    for(i=0;i<3;i++){
        sum+=((*p)+i)->mark[s];
    }
    printf("%d avr mark=%.2f\n",s,sum/3);
}

int main(){
    stu (*p)[3];
    p=(stu (*)[3])malloc(3*sizeof(stu));
    int i,j,s;
    int sel;
    for(i=0;i<3;i++){
        scanf("%s%d",((*p)+i)->name,&((*p)+i)->age);
        for(j=0;j<3;j++){
            scanf("%d",&((*p)+i)->mark[j]);
        }
    }
    while(1){
        scanf("%d",&sel);
        //0号功能进行名字从小到大排序；
        //1号功能进行年龄从小到达排序；
        //2号功能选择科目后进行由单科成绩由高到低排序；
        //3号功能选择科目后求该科目三人平均成绩。
        switch (sel){
        case 0:
            nsize(p);
            break;
        case 1:
            age(p);
            break;
        case 2:
            scanf("%d",&s);
            mark(p,s);
            break;
        case 3:
            scanf("%d",&s);
            avr(p,s);
            break;
        default:
            break;
        }
        for(i=0;i<3;i++){
            printf("%s %d",((*p)+i)->name,((*p)+i)->age);
            for(j=0;j<3;j++){
                printf(" %d",((*p)+i)->mark[j]);
            }
            printf("\n");
        }
    }

    return 0;
}