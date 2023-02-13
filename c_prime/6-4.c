#include <stdio.h>
int main() {
    char s[2];
    s[0] = '1';
    s[1] = '\0';
    printf("s = %s\n", s);

    char t[2];
    t[0] = '1';
    //t[1] = '\0';
    printf("t = %s\n", t);

    return 0;
}