#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {
	vector<double>v1;
	cout << v1.size() <<" " << v1.max_size() << endl;

	vector<char>v2;
	cout << v2.size() << " " << v2.max_size() << endl;

	vector<int>v3 = {1,2,3,4};
	cout << v3.size() << " " << v3.max_size() << endl;

	for (auto itr = v3.begin(); itr < v3.end(); itr++) {
		cout << *itr << " ";
	}
	cout << endl;
	for (auto itr = v3.rbegin(); itr < v3.rend(); itr++) {
		cout << *itr << " ";
	}
	cout << endl;
	for (auto itr = v3.cbegin(); itr < v3.cend(); itr++) {
		cout << *itr << " ";
	}
	cout << endl;

	v3.insert(v3.begin(), 0);
	for (auto itr = v3.begin(); itr < v3.end(); itr++) {
		cout << *itr << " ";
	}
	cout << endl;

	v3.insert(v3.end(), 0);
	for (auto itr = v3.begin(); itr < v3.end(); itr++) {
		cout << *itr << " ";
	}
	cout << endl;
#if 0
	不允许使用rend，rbegin，该迭代器返回reverse_iterator，	begin迭代器返回iterator
	v3.insert(dynamic_cast<iterator>(v3.rend())), -1);
	for (auto itr = v3.begin(); itr < v3.end(); itr++) {
		cout << *itr << " ";
	}
	cout << endl;
#endif
	v3.pop_back();
	for (auto itr = v3.begin(); itr < v3.end(); itr++) {
		cout << *itr << " ";
	}
	cout << endl;

	v3.push_back(5);
	for (auto itr = v3.begin(); itr < v3.end(); itr++) {
		cout << *itr << " ";
	}
	cout << endl;

	return 0;
}