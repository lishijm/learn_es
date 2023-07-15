#include<iostream>
#include<memory>

using namespace std;

int main() {
	auto_ptr<int> p1(new int);
	cout << &p1 << endl;
	cout << p1.get() << endl;
	*p1=100;
	cout << *p1 << endl;

	auto_ptr<int> p2(p1);
	*p2= 42;
	cout << *p2 << endl;

	return 0;
}