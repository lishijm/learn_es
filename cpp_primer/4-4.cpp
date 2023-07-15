#include<iostream>
#include<string>
#include<stdio.h>

using namespace std;

class person{
private:
    string name;
    int age;
    string sex;
public:
    person();
    void set(const string _name,const int _age,const string sex);
    void show();
    void eat();
    void sleep();
    ~person();
};

person::person(){
    cout<<"person()"<<endl;
}

person::~person(){
    cout<<"~"<<endl;
}

void person::eat(){
    cout<<name<<" eat"<<endl;
}

void person::sleep(){
    cout<<name<<" sleep"<<endl;
}

void person::set(const string _name,const int _age,const string _sex){
    this->name=_name;
    this->age=_age;
    this->sex=_sex;
}

void person::show(){
    cout<<name<<age<<sex<<endl;
}

class student:virtual public person{
private:
    string school;
    int score;
public:
    student();
    void set(const string _name,int _age,const string _sex,const string _school,int _score);
    void show();
    ~student();
};

student::student(){
    cout<<"student()"<<endl;
}

void student::set(const string _name,int _age,const string _sex,const string _school,int _score){
    person::set(_name,_age,_sex);
    this->school=_school;
    this->score=_score;
}

void student::show(){
    person::show();
    cout<<school<<score<<endl;
}

student::~student(){
    cout<<"~stu"<<endl;
}

class talent:virtual public person{
public:
    talent();
    ~talent();
    void set(const string _name,int _age,const string _sex,const string _kind);
    void show();
private:
    string kind;
};

talent::talent(){
    cout<<"talent()"<<endl;
}

talent::~talent(){
    cout<<"~tal"<<endl;
}

void talent::set(const string _name,int _age,const string _sex,const string _kind){
    person::set(_name,_age,_sex);
    this->kind=_kind;
}

void talent::show(){
    person::show();
    cout<<kind<<endl;
}

class bachelor:public student,public talent{
private:
    string kind;
    int sort;
public:
    bachelor();
    void set(const string _name,int _age,const string _sex,const string _kind,int _sort);
    void show();
    ~bachelor();
};

bachelor::bachelor(){
    cout<<"bachelor()"<<endl;
}

bachelor::~bachelor(){
    cout<<"~bac"<<endl;
}

void bachelor::set(const string _name,int _age,const string _sex,const string _kind,int _sort){
    this->kind=_kind;
    this->sort=_sort;
    if(sort==0){
        string kindt;
        cin>>kindt;
        talent::set(_name,_age,_sex,kindt);
    }
    else if(sort==1){
        string school;
        int score;
        cin>>school>>score;
        student::set(_name,_age,_sex,school,score);
    }
}

void bachelor::show(){
    if(sort==0){
        cout<<"talent"<<kind<<endl;
        talent::show();
    }
    else if(sort==1){
        cout<<"student"<<kind<<endl;
        student::show();
    }
}

int main(){
    string name,sex,kind;
    int age,sort;
    cin>>name>>age>>sex>>kind>>sort;
    bachelor bac1;
    bac1.set(name,age,sex,kind,sort);
    bac1.show();
    bac1.eat();
    bac1.sleep();

    return 0;
}