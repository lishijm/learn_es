#include <iostream>

using namespace std;

template<typename T1, class T2> auto mydiv(T1 a1, T2 a2) -> decltype(a1 / a2) {
	if (a2 == 0) {
		throw "0";
	}
    else{
        return a1/a2;
    }
}

int main() {
	int a = 5, b = 0;
    try{
        mydiv(a,b);
    }
    catch(const char *errmsg){
        cout<<errmsg<<endl;
    }
    cout<<"72"<<endl;

	return 0;
}