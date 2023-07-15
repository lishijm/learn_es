#include<iostream>
#include<stdio.h>

using namespace std;

void sum(int &a,int &b,int &sumn)
{
    sumn=a+b;
}

int main()
{
    int a,b,sumn;
    cin>>a;
    cin>>b;
    sum(a,b,sumn);
    cout<<sumn<<endl;

    return 0;
}