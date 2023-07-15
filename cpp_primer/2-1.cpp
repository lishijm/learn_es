#include<iostream>
#include<string>
using namespace std;

class vol{
    public:
        string name;
        int high,len1,len2,vol;
    private:
        void volx()
        {
            vol=high*len1*len2;
        }
    public:
        void print()
        {
            volx();
            cout<<name<<"'s vol="<<vol<<endl;
        }
};

int main()
{
    vol x;
    cin>>x.name;
    cin>>x.high>>x.len1>>x.len2;
    x.print();
}