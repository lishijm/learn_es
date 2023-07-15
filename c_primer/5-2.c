#include<stdio.h>
int main(){
    int mark;
    scanf("%d",&mark);
    if(mark>90){
        printf("A");
    }
    else if(mark>75){
        printf("B");
    }
    else if(mark>=60){
        printf("C");
    }
    else if(mark<60){
        printf("D");
    }

    return 0;
}