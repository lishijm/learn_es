#include<stdio.h>
#include<iostream>
using namespace std;
void swap(int &ap,int &bp)
{
    int tmp;
    tmp=ap;
    ap=bp;
    bp=tmp;
}

int main()
{
    int a=5,b=10;
    swap(a,b);
    cout<<a<<" "<<b<<endl;

    return 0;
}