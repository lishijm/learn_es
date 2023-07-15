#include<stdio.h>

enum a{
    mon,
    tue,
    wed,
    thu=12,
    fri,
    sat,
    sun,
};

int main(){
    printf("%d,",mon);
    printf("%d",sun);
}