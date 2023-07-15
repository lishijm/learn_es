#include <iostream>

using namespace std;

template<class T, size_t Size>
class mytmp {
private:
	T *pbase = nullptr;
	int size = 0;
private:
	T operator[](int index) {
		if (index < Size) {
			return *(this->phase + index);
		}
		else {
			cout << "out of range" << endl;
			return static_cast <T>(-1);
		}
	}
public:
	mytmp() {
		this->size = 0;
		this->pbase = new T[Size];
	}
	~mytmp() {
		delete[]this->pbase;
		this->size = 0;
	}
	bool isempty() {
		if (this->size == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	bool isfull() {
		if (this->size == Size) {
			return true;
		}
		else {
			return false;
		}
	}
	bool push(T data) {
		if (this->isfull()) {
			cout << "this stack isfully,cannot push!" << endl;
			return false;
		}
		else {
			this->pbase[this->size] = data;
			this->size++;
			return true;
		}
	}
	T pop() {
		if (this->isempty()) {
			cout << "this stack is empty,cannot pop!" << endl;
			return static_cast<T>(-1);
		}
		else {
			T r = this->pbase[this->size-1];
			this->size--;
			return r;
		}
	}
};

int main() {
	int i;
	mytmp<int, 10> ls;
	for (i = 0; i <=10; i++) {
		ls.push((i + 2) * 2);
	}
	for (i = 0; i <=10; i++) {
		cout << ls.pop() << endl;
	}
    
	return 0;

}