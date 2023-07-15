#include<iostream>

using namespace std;


template<typename T1 > auto mysort(T1 &a) {
	int size = sizeof(a) / sizeof(a[0]);
	int i, j;
	double tmp;
	for (i = 0; i < size-1; i++) {
		for (j = 0; j < size - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				tmp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = tmp;
			}
		}
	}
}

int main() {
	double arr[] = { 1.5,2.4,1.3 };
	mysort(arr);
	int i;
	for (i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++) {
		cout << arr[i] << " ";
	}
	return 0;
}