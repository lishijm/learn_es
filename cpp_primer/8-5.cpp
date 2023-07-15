#include <iostream>
#include <stack>

using namespace std;

int main() {
	stack<int>stc1;
	for (int i = 0; i < 1000; i++) {
		stc1.push(i + 1 * 2);
	}
	cout << stc1.size() << endl;
	for (int i = 0; i < 500; i++) {
		stc1.pop();
	}
	cout << stc1.size() << endl;

	return 0;
}