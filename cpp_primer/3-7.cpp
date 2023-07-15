#include <iostream>
using namespace std;

#include <string>


class AA
{
public:
	AA(int _a, int _b) :a(_a), b(_b)
	{
        
	}
	~AA()
	{
		cout << "~AA()" << endl;
	}
	void show()
	{
		cout << "a = " << a << endl;
		cout << "b = " << b << endl;
	}
	friend AA operator++(AA &aa);
private:
	int a;
	int b;
};
//友元实现运算符重载
AA operator++(AA &aa)
{
	cout << "++运算符重载" << endl;
    ++aa.a;
    ++aa.b;
	return aa;
}


int main()
{
	AA aa(1, 2), bb(2, 3);
    aa.show();
    bb.show();

    ++aa;
    aa.show();
    ++bb;
    bb.show();
    
	return 0;
}