#include <iostream>
#include <exception>

using namespace std;

template<typename T1, class T2> auto mydiv(T1 a1, T2 a2) -> decltype(a1 / a2) {
	if (a2 == 0) {
        throw exception();
	}
    return a1/a2;
}

int main() {
	int a = 5, b = 0;
    try{
        mydiv(a,b);
    }
    catch(exception &e){
        cout<<e.what()<<endl;
    }
    cout<<"73"<<endl;
	return 0;
}