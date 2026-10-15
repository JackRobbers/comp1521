#include <stdint.h>
#include <stdio.h>

int main(void) {
    uint8_t num;
    scanf("%hhd", &num);

    printf("0%03o, 0x%02X\n", num, num);

    // no %b for binary

    // can binary literal

    uint8_t x = 0b10101010;
    uint8_t y = 0xAA;
    uint8_t z = 021;
    uint8_t a = 21;
}