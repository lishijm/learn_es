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

class student:public person{
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

class bachelor:public student{
private:
    string kind;
public:
    bachelor();
    void set(const string _name,int _age,const string _sex,const string _school,int _score,const string _kind);
    void show();
    ~bachelor();
};

bachelor::bachelor(){
    cout<<"bachelor()"<<endl;
}

bachelor::~bachelor(){
    cout<<"~bac"<<endl;
}

void bachelor::set(const string _name,int _age,const string _sex,const string _school,int _score,const string _kind){
    this->kind=_kind;
    student::set(_name,_age,_sex,_school,_score);
}

void bachelor::show(){
    person::show();
    student::show();
    cout<<kind<<endl;
}

int main(){
    string name,sex,school,kind;
    int age,score;
    cin>>name>>age>>sex>>school>>score>>kind;
    bachelor bac1;
    bac1.set(name,age,sex,school,score,kind);
    bac1.show();
    bac1.eat();
    bac1.sleep();

    return 0;
}