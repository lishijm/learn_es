#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int>vec1;
	for (int i = 0; i < 1000; i++) {
		vec1.push_back(i * 2);
	}
#if 0
	for (auto itr = vec1.begin(); itr != vec1.end(); itr++) {
		cout << *itr << " ";
	}
#endif
	vec1.push_back(5);
	cout << clock();
}