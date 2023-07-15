#include <iostream>
#include <stdio.h>
#include <string>
#include <exception>

using namespace std;

class xdiv:public exception{
private:
    string message;
public:
    xdiv(string errmsg):message(errmsg){
    }
    virtual const char *what() const noexcept{
        cout<<"what()"<<endl;
        return this->message.data();
    }
};

template<class T1,class T2> auto divf(T1 a1,T2 a2){
    if(a2==0){
        throw xdiv("a2=0");
    }
    else{
        return a1/a2;
    }
}

int main(){
    int a=4;
    double b=0.0;

    try{
        auto ret=divf(a,b);
        cout<<ret<<endl;
    }
    catch(xdiv& err){
        cout<<err.what()<<endl;
    }
    catch (exception& err) {
        cout << err.what() << endl;
    }
    return 0;
}