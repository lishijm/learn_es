//自定义无参有参构造函数
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
        vol()
        {
            string name;
            int high,len1,len2,volr;
            cin>>name;
            cin>>high>>len1>>len2;
            volr=volx(high,len1,len2);
            cout<<name<<"'s vol="<<volr<<endl;
        }
        vol(int &h,int&l1,int &l2,string &name)
        {
            int volr=volx(h,l1,l2);
            cout<<name<<"'s vol="<<volr<<endl;
        }
        vol(string &name)
        {
            cout<<name<<endl;
        }
};

int main()
{
    //函数重载
    vol vol1;//正确的无参
    //vol vol1();错误的无参
    string name;
    int high,len1,len2;
    cin>>name;
    cin>>high>>len1>>len2;
    vol vol2(high,len1,len2,name);
    vol vol3(name);

}