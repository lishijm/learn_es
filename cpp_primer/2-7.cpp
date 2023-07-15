//指针
#include<iostream>
#include<string>
using namespace std;

class vol{
    private:
        int volx(int &h,int &l1,int &l2)
        {
            return h*l1*l2;
        }
    public:
        void vol1(int &h,int&l1,int &l2,string &name)
        {
            int volr=volx(h,l1,l2);
            cout<<name<<"'s vol="<<volr<<endl;
        }
};

int main()
{
    string name;
    int heigh,len1,len2;
    vol *p=new vol();
    cin>>name>>heigh>>len1>>len2;
    p->vol1(heigh,len1,len2,name);

    return 0;
}