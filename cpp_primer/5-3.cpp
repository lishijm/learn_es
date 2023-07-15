#include<iostream>

using namespace std;

class A {
private:
	int val=1;
public:
	void imgshow(int val) {
		cout << "imgshow A" << endl;
		cout << val << endl;
	}
};

class B :public A {
private:
	int val=2;
public:
	void imgshow() {
		cout << "imgshow B" << endl;
	}
};

int main() {
	B b1;
#if 0
	b1.A::imgshow();
	b1.imgshow(12);
#endif
	b1.imgshow();
	A* p = new B;
	p->imgshow(12);
}