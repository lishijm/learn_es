#include <iostream>
#include <deque>

using namespace std;

int main() {
	deque<int>deq1;
	for (int i = 0; i < 1000; i++) {
		deq1.push_back(i+1 * 2);
	}

	for (auto itr = deq1.begin(); itr != deq1.end(); itr++) {
		cout << *itr << " ";
	}
	cout << endl;
	cout << deq1.size() << endl;
	for (int i = 0; i < 500; i++) {
		deq1.pop_front();
	}
	for (auto itr = deq1.begin(); itr != deq1.end(); itr++) {
		cout << *itr << " ";
	}
	cout << endl;
	cout << deq1.size() << endl;

	return 0;
}