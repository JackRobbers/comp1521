#include <stdio.h>
#include <stdint.h>

int main(void) {
    uint8_t a = 3;
    uint8_t b = 4; 
    uint8_t res = a + b;

    printf("%d0000\n", res);
}
