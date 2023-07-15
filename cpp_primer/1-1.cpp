#include<stdio.h>

namespace INA
{
    int val=1;
} // namespace INA

namespace INB
{
    int val=2;    
} // namespace INB

using namespace INA;

int main()
{
    printf("%d %d\n",val,INA::val);
    printf("%d\n",INB::val);

    return 0;
}