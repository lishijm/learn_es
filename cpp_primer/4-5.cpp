#include<stdio.h>
#include<string>
#include<iostream>
#include<string.h>

using namespace std;

typedef struct whestr{
    string state[100];
    int size;
} whes;

class vehicle
{
private:
    string band;
public:
    int wheels;
    vehicle();
    void set(int,const string);
    void show();
    ~vehicle();
};

vehicle::vehicle(){
    cout<<"veh()"<<endl;
}

void vehicle::set(int _wheels,const string _band){
    this->wheels=_wheels;
    this->band=_band;
}

void vehicle::show(){
    cout<<band<<endl;
}

vehicle::~vehicle(){
    cout<<"~veh()"<<endl;
}

class wheel:public vehicle
{
private:
    whes *p;
public:
    wheel();
    void set();
    void restate();
    ~wheel();
};

wheel::wheel()
{
    p=(whes *)malloc(sizeof(whes));
    memset(p,0,sizeof(whes));
    cout<<"whe()"<<endl;
}

wheel::~wheel(){
    free(p);
    cout<<"~whe()"<<endl;
}

void wheel::set(){
    //cout<<wheels;
    int i;
    p->size=wheels;
    string _state;
    for(i=0;i<p->size;i++){
        cin>>_state;
        p->state[i]=_state;
    }
}

void wheel::restate(){
    int i;
    for(i=0;i<p->size;i++){
        cout<<"车轮"<<i+1<<this->p->state[i]<<endl;
    }
    cout<<endl;
}

int main(){
    int wheels;
    string band;
    cin>>band>>wheels;
    wheel whe1;
    whe1.vehicle::set(wheels,band);
    whe1.set();
    whe1.show();
    whe1.restate();

    return 0;
}