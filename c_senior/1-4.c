#include<stdio.h>
struct s1{
    char name[10];
    int id;
};
int main(){
    int i;
    struct s1 user[10];
    for(i=0;i<2;i++){
        scanf("%s%d",user[i].name,&user[i].id);
    }
    for(i=0;i<2;i++){
        printf("%s,%d\n",user[i].name,user[i].id);
    }
    
    return 0;
}