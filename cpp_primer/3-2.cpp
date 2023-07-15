//static
#include<stdio.h>
#include<iostream>
#include<string>

using namespace std;

class door{
private:
    static int state;
    static string id;
    string key="小明";
    void judege();
    void action();
public:
    door(const string name);
    ~door();
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

door::door(const string name)
{
    id=name;
    judege();
}

door::~door()
{
    cout<<"~"<<endl;
}

int door::state=0;

string door::id;

int main()
{
    while(1){
        string name;
        cin>>name;
        if(0==name.compare("quit")){
            break;
        }
        door dor1(name);
    }

    return 0;
}