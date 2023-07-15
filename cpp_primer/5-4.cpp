#include<iostream>

using namespace std;

class A {
private:
	int val = 1;
public:
	virtual void imgshow() {
		cout << "imgshow A" << endl;
	}
};

class B :public A {
private:
	int val = 2;
public:
	void imgshow() {
		cout << "imgshow B" << endl;
	}
#if 0
	//不构成重写
	void imgshow(int _val) {
		cout << _val << endl;
	}
#endif
};

int main() {
	B b1;
	b1.A::imgshow();
#if 0
	b1.imgshow(12);
#endif
	b1.imgshow();
	A* p = new B;
	p->imgshow();
}