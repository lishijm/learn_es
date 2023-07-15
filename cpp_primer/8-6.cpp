#include<iostream>
#include<map>

using namespace std;

int main() {
	map<int, string, double>map1;
	map1[1] = "a", 2.4;
	map1[2] = "b", 3.5;
	auto ret = map1.find(1);
	cout << ret->second << endl;
}