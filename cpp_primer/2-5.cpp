//析构
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
        ~vol(){
            cout<<"none"<<endl;
        }
};

int main()
{
    string name;
    cin>>name;
    vol vol1;
    vol vol(name);
    while(1);

    return 0;
}