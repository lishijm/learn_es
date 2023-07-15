//战斗机
#include<stdio.h>
#include<string>
#include<iostream>

using namespace std;

class fighter{
public:
    int id;
    static int fs;
    void death(const int);
    void recmd();
    ~fighter(){
        cout<<"~"<<endl;
    }
private:
    int state=1;
};

void fighter::death(const int dea)
{
    if(dea==id){
        cout<<id<<"号无"<<endl;
        state=0;
        fs--;
    }
}

void fighter::recmd()
{
    if(state==1){
        cout<<id<<"回复"<<fs<<"剩余"<<endl;
    }
}

int fighter::fs=0;

int main()
{
    int fsmain=0,i=0,deid;
    cin>>fsmain;
    fighter fly[fsmain];
    for(i=0;i<fsmain;i++){
        fly[i].id=i+1;
    }
    fighter::fs=fsmain;
    int remain=fsmain;
    while(1){
        if(remain==0){
            break;
        }
        cin>>deid;
        for(i=0;i<fsmain;i++){
            fly[i].death(deid);
        }
        for(i=0;i<fsmain;i++){
            fly[i].recmd();
        }
        remain--;
    }

    return 0;
}