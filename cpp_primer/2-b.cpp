#include <iostream>
#include<string>
#include<stdio.h>
#include<string.h>

using namespace std;
int state=0;

class person{
public:
    string id;
    person(){
        cin>>id;
    }
    void display();
};

void person::display(){
    cout<<id<<endl;
}

//--------------------------

class door{
private:
    string id;
    string key="小明";
    void judege();
    void action();
public:
    void lock(const string name);
};

void door::judege()
{
    if(0==(door::key.compare(door::id))){
        action();
    }
    else{
        cout<<"拒绝访问"<<endl;
    }
}

void door::action()
{
    if(state==0){
        cout<<"门已开"<<endl;
        state=1;
    }
    else if(state==1){
        cout<<"门已关"<<endl;
        state=0;
    }
}

void door::lock(const string name)
{
    id=name;
    cout<<id<<endl;
    judege();
}

//----------------------------

int main()
{
    string name;
    while(1){
        person per1;
        per1.display();
        door dor1;
        dor1.lock(per1.id);
    }

}