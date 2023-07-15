//深拷贝
#include<stdio.h>
#include<string>
#include<iostream>
#include<string.h>

using namespace std;

class deepcopy
{
private:
    int a,b,*p;
public:
    deepcopy(/* args */);
    void num(int a,int b);
    void copy(const deepcopy &dc);
    ~deepcopy();
    void show();
};

deepcopy::deepcopy(/* args */)
{
    cout<<"depc()"<<endl;
}

deepcopy::~deepcopy()
{
    delete[]p;
    cout<<"~depc()"<<endl;
}

void deepcopy::num(int _a,int _b){
    int i;
    a=_a;
    b=_b;
    p=new int[a]();
    for(i=0;i<a;i++){
        p[i]=b;
    }
}

void deepcopy::copy(const deepcopy&dc){
    a=dc.a;
    b=dc.b;
    p=new int[a]();
    memcpy(p,dc.p,sizeof(int)*a);
}

void deepcopy::show(){
    int i;
    cout<<"a= "<<a<<"b= "<<b<<endl;
    for(i=0;i<a;i++){
        cout<<p[i]<<" ";
    }
    cout<<endl;
}

int main(){
    deepcopy dem1;
    dem1.num(5,2);
    dem1.show();
    deepcopy dem2;
    dem2.copy(dem1);
    dem2.show();

    return 0;
}