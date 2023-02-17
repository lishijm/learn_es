#include<stdio.h>

double fun(double num){
    if(num==1||num==0){
        return 1;
    }
    return num*fun(num-1);
}
int main(){
    double n;
    scanf("%lf",&n);
    printf("%g\n",fun(n));

    return 0;
}