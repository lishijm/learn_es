#include<iostream>
#include<array>

using namespace std;

int main() {
	array<double, 30 >arr= {2.3, 4.6, 0.25};
	cout << arr.size() << endl;
	cout << arr.max_size() << endl;
	int i;
	for (int i = 0; i < arr.size(); i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	for (auto itr = arr.begin(); itr< arr.end(); itr++) {
		cout << *itr<<" ";
	}
	cout << endl;
	for (auto itr = arr.begin(); itr < arr.end(); itr++) {
		cout << *itr << " ";
	}
	cout << endl;
	for (auto itr = arr.crbegin(); itr < arr.crend(); itr++) {
		cout << *itr << " ";
	}
	cout << endl;
	/*for (i = 0; i < arr.size()-5; i++) {
		arr[i]= i * 2.1;
	}
	cout << endl;*/
	return 0;
}