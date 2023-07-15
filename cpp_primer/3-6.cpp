#include <iostream>
using namespace std;

#include <string>


class AA
{
public:
	AA(int _a, int _b) :a(_a), b(_b)
	{
		cout <<a<<" "<<b<< endl;
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
	friend AA operator+(AA &aa, AA &tmp);
private:
	int a;
	int b;
};
//友元实现运算符重载
AA operator+(AA &aa, AA &bb)
{
	cout << "+运算符重载" << endl;
	AA sum(0, 0);
	sum.a = aa.a + bb.a;
	sum.b = aa.b + bb.b;
	return sum;
}


int main()
{
	int a = 10, b = 5;
	int c = a + b;

	AA aa(1, 2), bb(2, 3);
	AA cc = aa + bb;  //AA cc = operator+(&aa, bb);
	cc.show();
    
    string str1 = "aaa", str2 = "bbb";
	string str3 = str1 + str2;
	cout << str3 << endl;
	return 0;
}