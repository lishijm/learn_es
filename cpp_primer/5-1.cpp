#include<stdio.h>
#include<string>
#include<iostream>
#include<string.h>
#include<array>

using namespace std;

class cla {
private:
    int c;
    char b;
    double f;
    char e;
public:
    void set_c(int val);
    void set_b(int val);
    void size();
};

void cla::set_c(int val) {
    this->c = val;
}
void cla::set_b(int val) {
    this->b = val;
}

void cla::size() {
    cout << sizeof(e) << endl;
}

class clb :public cla {
private:
    int bb;
    int cc;
    double dd;
public:
    auto get_bb() -> decltype(this->bb) {
        return this->bb;
    }
};
/*
class clb       size(40) :
    +-- -
    0 | +-- - (base class cla)
    0      | | c
    4      | | b
    | | <alignment member> (size = 3)
    8      | | f
    16      | | e
    | | <alignment member> (size = 7)
    | +-- -
    24 | bb
    28 | cc
    32 | dd
    + -- -
*/
template <typename T, typename T1> auto myadd(T a, T1 b) -> decltype(a + b) {
    return a + b;
}

int main() {
    cout <<"sizeof(cla)=" << sizeof(cla) << endl;
    cout << "sizeof(clb)=" << sizeof(clb) << endl;
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