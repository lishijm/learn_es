#include <iostream>
#include <list>

using namespace std;

int main() {
	list<int>lis1;
	for (int i = 0; i < 1000; i++) {
		lis1.push_back(i * 2);
	}
#if 0
	for (auto itr = lis1.begin(); itr != lis1.end(); itr++) {
		cout << *itr << " ";
	}
#endif
	lis1.push_back(5);
	cout << clock();
}