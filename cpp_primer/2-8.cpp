#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

class square
{
private:
    int len1,len2;
public:
    square(int _len1,int _len2);
    square(const square &squ);
    ~square();
    void display();
};

square::square(int _len1,int _len2)
{
    len1=_len1;
    len2=_len2;
}
square::square(const square &squ)
{
    this->len1=squ.len1;
    this->len2=squ.len2;
}
square::~square()
{
    cout<<"~square"<<endl;
}
void square::display()
{
    cout<<len1*len2<<endl;
}
int main()
{
    int length1,legenth2;
    cin>>length1>>legenth2;
    square squ1(length1,legenth2);
    squ1.display();
    square squ2(squ1);
    squ2.display();

    return 0;
}