#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

class square
{
private:
    int len1,len2;
    int area();
    int grith();
public:
    square(int _len1,int _len2);
    ~square();
};

square::square(int _len1,int _len2)
{
    len1=_len1;
    len2=_len2;
    int arear=area();
    int grithr=grith();
    cout<<"area="<<arear<<endl;
    cout<<"grith="<<grithr<<endl;
}

square::~square()
{
    cout<<"~square"<<endl;
}

int square::area()
{
    return len1*len2;
}

int square::grith()
{
    return 2*(len1+len2);
}

int main()
{
    int length1,legenth2;
    cin>>length1>>legenth2;
    square squ1(length1,legenth2);

    return 0;
}