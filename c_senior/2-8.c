#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stu{
    char name[20];
    int age;
    int mark[3];
} c1[3];

void nsize(struct stu (*p)[3]){
    int i,j;
    struct stu tmp;

    for(i=0;i<3;i++){
        for(j=0;j<3-i-1;j++){
            if((strcmp((((*p)+j)->name),(((*p)+j+1)->name)))>0){
                tmp=c1[j+1];
                c1[j+1]=c1[j];
                c1[j]=tmp;
            }
        }
    }
}

void age(struct stu (*p)[3]){
    int i,j;
    struct stu tmp;

    for(i=0;i<3;i++){
        for(j=0;j<3-i-1;j++){
            if(((*p)+j)->age>((*p)+j+1)->age){
                tmp=c1[j+1];
                c1[j+1]=c1[j];
                c1[j]=tmp;
            }
        }
    }
}

void mark(struct stu (*p)[3],int s){
    int i,j;
    struct stu tmp;

    for(i=0;i<3;i++){
        for(j=0;j<3-i-1;j++){
            if(((*p)+j)->mark[s]<((*p)+j+1)->mark[s]){
                tmp=c1[j+1];
                c1[j+1]=c1[j];
                c1[j]=tmp;
            }
        }
    }
}

void avr(struct stu (*p)[3],int s){
    int i;
    float sum=0;
    struct stu tmp;

    for(i=0;i<3;i++){
        sum+=((*p)+i)->mark[s];
    }
    printf("%d avr mark=%.2f",s,sum/3);
}

int main(){
    
    struct stu (*p)[3]=&c1;
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
        switch (sel){
        case 0:
            nsize(&c1);
            break;
        case 1:
            age(&c1);
            break;
        case 2:
            scanf("%d",&s);
            mark(&c1,s);
            break;
        case 3:
            scanf("%d",&s);
            avr(&c1,s);
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