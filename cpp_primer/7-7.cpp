#include<iostream>
#include<memory>

using namespace std;

int main() {
	shared_ptr<int> parr(new int[20], [](int* p) {delete[] p; });
	for (int i = 0; i < 20; i++) {
		*(parr.get() + i) = i*2;
	}

	cout << parr << endl;
	cout << parr.get() << endl;
	cout << *(parr.get()) << endl;

	for (int i = 0; i < 20; i++) {
		cout << *(parr.get() + i) << " ";
	}
	cout << endl;
}