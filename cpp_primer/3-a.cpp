//顺序表封装
#include<stdio.h>
#include<string>
#include<iostream>
#include<string.h>

using namespace std;
# define max 20

typedef struct tablelist{
    int val[max];
    int size;
} stable;

class table{
public:
    void start()
    {
        initable();
    }
    ~table()
    {
        cout<<"~"<<endl;
    }
    void creat(const int n);
    void print();
    //void insert(int i,int ele);
    friend table operator+(table &t1,int i);
private:
    stable *tp;
    void initable();
    void printi(int i);
};

void table::initable()
{
    tp=(stable *)malloc(sizeof(stable));
    memset(tp,0,sizeof(stable));
    tp->size=0;
}

void table::creat(const int n)
{
    int i;
    for(i=0;i<n;i++){
        cin>>tp->val[i];
    }
    tp->size=n;
}

void table::print()
{
    int i;
    for(i=0;i<tp->size;i++){
        cout<<tp->val[i]<<" ";
    }
    cout<<endl;
}

void table::printi(int i)
{
    cout<<tp->val[i-1]<<endl;
}

// void table::insert(int i,int ele)
// {
//     i--;
//     if(i>=0&&i<tp->size){
//         int j=tp->size-1;
//         while(j>=i){
//             tp->val[j+1]=tp->val[j];
//             j--;
//         }
//         tp->val[i]=ele;
//         tp->size++;
//     }
// }

table operator+(table &t1,int i)
{
    t1.printi(i);
    return t1;
}

int main()
{
    int sizemain;
    cin>>sizemain;
    table t1;
    t1.start();
    t1.creat(sizemain);
    t1.print();
    int i;
    cin>>i;
    t1+i;
}