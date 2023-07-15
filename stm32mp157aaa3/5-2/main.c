#include "uart4.h"

int main(){
    char ch;
    uart_init();
    while (1){
        ch=recv();
        send(ch);
    }
}