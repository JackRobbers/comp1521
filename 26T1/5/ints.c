#include <stdint.h>
#include <stdio.h>

int main(void) {
    uint8_t num = 5;
    num =  num - 10;
    printf("%d\n", num);

    // signed int overflow

    int8_t num2 = 100;
    num2 = num2 + 50;
    printf("%d\n", num2);

    int x = 043;
    printf("%d\n", x);
}

