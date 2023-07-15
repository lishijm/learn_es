#include"../include/class.h"
int main(){
    stu c1[3];
    stu (*p)[3]=&c1;
    //p=(stu (*)[3])malloc(3*sizeof(stu));
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