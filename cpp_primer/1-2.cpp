#include<stdio.h>
#include<iostream>

namespace INA
{
    int val=1;
} // namespace INA

namespace INB
{
    int val=2;    
} // namespace INB

using namespace INA;
using namespace std;


int main()
{
    printf("%d %d\n",val,INA::val);
    printf("%d\n",INB::val);
    printf("%d\n", val);
    printf("%d\n", INB::val);
    cout << "INA::val=" << val<<endl;
    cin >> val >> INB::val;
    cout << val << endl;
    cout << INB::val<<endl;
    int &b=val;
    b=b+val;
    //int &b=INB::val;
    cout<<b<<endl;

    return 0;
}