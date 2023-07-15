#include<iostream>

using namespace std;

class grand {
public:
	virtual int  test() {
		cout << "gand" << endl;
		return 0;
	}
};

class father :virtual public grand {
public:
	virtual int  test() {
		cout << "father" << endl;
		return 0;
	}
};

class father2 :virtual public grand {
public:
	virtual int  test() {
		cout << "father2" << endl;
		return 0;
	}
};

class son :public father, public father2 {
public:
	virtual int  test() {
		cout << "son" << endl;
		return 0;
	}
};

int main() {

	return 0;
}