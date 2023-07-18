#include <stdio.h>

int *p(char a){
    return 0;
}

struct demo1
{
    char a[4];
    char b;
};


struct demo2
{
    char a[4];
    char b;
    int c;
};

struct demo3
{
    char a[4];
    char b;
    int c;
    double d;
};

struct demo4
{
    char a[4];
    char b;
    short c;
};

int main(){    
    printf("%d\n",5);
    printf("%ld\n",5.01);
    printf("%f\n",5);

    printf("%d\n",sizeof(p('x')));

    struct demo1 sdemo1;
    printf("%d\n",sizeof(sdemo1));

    struct demo2 sdemo2;
    printf("%d\n",sizeof(sdemo2));

    struct demo3 sdemo3;
    printf("%d\n",sizeof(sdemo3));

    struct demo4 sdemo4;
    printf("%d\n",sizeof(sdemo4));

    return 0;
}