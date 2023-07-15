#include <iostream>
using namespace std;

#include <string>


class AA
{
public:
	AA(int _a = 0, int _b = 0) :a(_a), b(_b)
	{
		cout << "AA(int, int)" << endl;
	}
	AA(const AA &aa)
	{
		a = aa.a;
		b = aa.b;
		cout << "AA(&)" << endl;
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
	/*
	 AA &operator++()
	 {
		 ++this->a;
		 ++this->b;
		 return *this; //*this <=>aa
	 }
	 */

	AA operator++(int)  //int只是为了表示此时是后置++
	{
		AA tmp = *this;
	    this->a++;
		this->b++;
		return tmp;
	}

	//friend AA operator++(AA &aa, int);
	friend  AA &operator++(AA &aa);
	friend void operator<<(ostream &out, AA &aa);
private:
	int a;
	int b;
};


AA &operator++(AA &aa)
{
	++aa.a;
	++aa.b;
	return aa;
}

/*AA operator++(AA &aa, int)  //int只是为了表示此时是后置++
{
	AA tmp = aa;
	aa.a++;
	aa.b++;
	return tmp;
}*/

void operator<<(ostream &out, AA &aa)
{
	out << "a = " << aa.a << endl;
	out << "b = " << aa.b << endl;
}

int main()
{
	int a = 10, b = 5;
	int c = a + b;

	AA aa(1, 2), bb(2, 3);
	bb = ++aa;  //operator++(&aa);  ++aa = aa;  将aa自增后的值返回
	aa.show();
	bb.show();

	bb = aa++;
	aa.show();
	bb.show();

	cout << aa;   //只能通过友元实现
	string str1 = "aaa";
	cout << str1 << endl;  //string类中已经对<<进行了重载
	cout << str1[0] << endl; //string类对[]进行了重载
	return 0;
}
