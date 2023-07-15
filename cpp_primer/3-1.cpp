//const
#include<stdio.h>
#include<iostream>
#include<string>

using namespace std;

class test{
private:
    mutable int a;
    mutable int b;
public:
    void setab(int _a,int _b) const
    {
        this->a=_a;
        this->b=_b;
    }
    void show()
    {
        cout<<"a="<<a<<"b="<<b<<endl;
    }
};

int main()
{
    test t1;
    t1.setab(1,2);
    t1.show();
}