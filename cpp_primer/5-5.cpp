#include<iostream>

using namespace std;

class A {
public:
	A() {
		cout << "A()" << endl;
	}
	virtual ~A() {
		cout << "~A()" << endl;
	}
};

class B :public A {
public:
	B() {
		cout << "B()" << endl;
	}
	~B() {
		cout << "~B()" << endl;
	}
};

class C :public B {
public:
	C() {
		cout << "C()" << endl;
	}
	~C() {
		cout << "~C()" << endl;
	}
};

int main() {
	A* p = new C;
	delete p;

	return 0;
}