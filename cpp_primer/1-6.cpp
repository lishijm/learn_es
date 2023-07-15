#include<iostream>
#include<stdio.h>

using namespace std;

typedef struct st{
    int id;
    char name;
} sst;

void print_arry(int *arn,int num)
{
    int i;
    for(i=0;i<num;i++){
        cout<<arn[i]<<endl;
    }
}

void print_arry(char *str,int num)
{
    int i;
    for(i=0;i<num;i++){
        cout<<str[i]<<endl;
    }
}

void print_arry(sst *ssp,int num)
{
    int i;
    for(i=0;i<num;i++){
        cout<<ssp[i].id<<ssp[i].name<<endl;
    }
}

int main()
{
    int number=3;
    int arn[number]={0,1,2};
    char str[number]={'a','b','c'};
    sst sstr[number];
    sstr[0].id=3;
    sstr[0].name='A';
    sstr[1].id=6;
    sstr[1].name='B';
    sstr[2].id=9;
    sstr[2].name='C';
    print_arry(arn,number);
    print_arry(str,number);
    print_arry(sstr,number);
}