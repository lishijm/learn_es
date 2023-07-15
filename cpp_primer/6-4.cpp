#include<iostream>
#include<array>

using namespace std;

namespace mytem {
	template<typename T1 > auto mysort(T1& p) {
		int i, j;
		double tmp;
		for (i = 0; i < p->size(); i++) {
			for (j = 0; j < p->size() - i - 1; j++) {
				if ((*p)[j] > (*p)[j + 1]) {
					tmp = (*p)[j + 1];
					(*p)[j + 1] = (*p)[j];
					(*p)[j] = tmp;
				}
			}
		}
	}
}

int main() {
	array<double, 3>arr{ 1.5,2.4,1.3 };
	auto p = &arr;
	mytem::mysort(p);
	int i;
	for (auto x:arr) {
		cout << x << " ";
	}
	return 0;
}