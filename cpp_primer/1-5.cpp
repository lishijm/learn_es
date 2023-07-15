#include<iostream>
#include<stdio.h>

using namespace std;

int sum(int a,int b,int c=0,int d=0)
{
    return a+b+c+d;
}

void fun()
{
    printf("xxx\n");
}

int main()
{
    int a,b,c,d,sumn;
    cin>>a;
    cin>>b;
    sumn=sum(a,b);
    cout<<sumn<<endl;
    cin>>a;
    cin>>b;
    cin>>c;
    cin>>d;
    sumn=sum(a,b,c,d);
    cout<<sumn<<endl;
    fun();

    return 0;
}