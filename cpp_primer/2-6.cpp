//堆区
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
        vol(int h,int l1,int l2,string name)
        {
            int volr=volx(h,l1,l2);
            cout<<name<<"'s vol="<<volr<<endl;
        }
        vol(string name)
        {
            cout<<name<<endl;
        }
        ~vol(){
            cout<<"none"<<endl;
        }
};

int main()
{
    vol *vp1=new vol[2];
    vol *vp2=new vol("box2");
    delete []vp1;
    delete vp2;
    return 0;
}