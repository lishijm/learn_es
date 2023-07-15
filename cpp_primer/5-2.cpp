#include<stdio.h>
#include<string>
#include<iostream>
#include<string.h>
#include<array>

using namespace std;

class cla {
private:
    int claa;
    char clab;
    double clac;
    char clad;
public:
    void set_c(int val);
    void set_b(int val);
    void size();
};

void cla::set_c(int val) {
    this->claa = val;
}
void cla::set_b(int val) {
    this->clac = val;
}

void cla::size() {
    cout << sizeof(cla) << endl;
}

class clb:virtual public cla {
private:
    int clba;
    int clbb;
    double clbc;
public:
    auto get_bb() -> decltype(this->clba) {
        return this->clba;
    }
};

class clc :virtual public cla {
private:
    int clca;
    double clcb;
};

class cld :public clb,clc {
    int clda;
};

template <typename T, typename T1> auto myadd(T a, T1 b) -> decltype(a + b) {
    return a + b;
}

int main() {
    cout << "sizeof(cla)=" << sizeof(cla) << endl;
    cout << "sizeof(clb)=" << sizeof(clb) << endl;
    cout << "sizeof(clc)=" << sizeof(clc) << endl;
    cout << "sizeof(cld)=" << sizeof(cld) << endl;
    int c = 9;
    double b = 3.12;
    int f = 4;
    auto e = myadd(c, b);
    auto h = myadd(c, f);
    cout << e << "\t" << typeid(e).name() << endl;
    cout << h << "\t" << typeid(h).name() << endl;

    array<double, 8> a1{ 1.2, 5.4, 8.9 };
    for (auto itr = a1.begin(); itr != a1.end(); itr++) {
        cout << *itr << " ";
    }
    cout << endl;

    return 0;
}