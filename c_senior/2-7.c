#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student{
    char name[20];
    int age;
    int mark[3];
} stu;

/*stu age(stu (*p)[3]){
    int i,j;
    stu **tmp;

    for(i=0;i<3;i++){
        for(j=0;j<3-i-1;j++){
            if(((*p)+j)->age>((*p)+j+1)->age){
                **tmp=*((*p)+j+1);
                *((*p)+j+1)=*((*p)+j);
                *((*p)+j)=**tmp;
            }
        }
    }
}*/

int main(){
    
    stu c1[3];
    stu (*p)[3]=&c1;
    int i,j;
    
    for(i=0;i<3;i++){
        scanf("%s%d",((*p)+i)->name,&((*p)+i)->age);
        for(j=0;j<3;j++){
            scanf("%d",&((*p)+i)->mark[j]);
        }
    }

        
    for(i=0;i<3;i++){
        for(j=0;j<3-i-1;j++){
            if(((*p)+j)->age>((*p)+j+1)->age){
                tmp=c1[j+1];
                c1[j+1]=c1[j];
                c1[j]=tmp;
            }
        }
    }
    
    for(i=0;i<3;i++){
        printf("%s%d",((*p)+i)->name,((*p)+i)->age);
        for(j=0;j<3;j++){
            printf("%d",((*p)+i)->mark[j]);
        }
        printf("\n");
    }

    return 0;
}