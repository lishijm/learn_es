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
        void print()
        {
            string name;
            int high,len1,len2,vol;
            cin>>name;
            cin>>high>>len1>>len2;
            vol=volx(high,len1,len2);
            cout<<name<<"'s vol="<<vol<<endl;
        }
};

int main()
{
    vol x;
    x.print();
}