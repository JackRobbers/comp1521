// take in a decimal number and output the 
// binary, octal, and hexadecimal forms

#include <stdio.h>
#include <stdint.h>

int main(void) {

    int8_t num;
    scanf("%hhd", &num);

    // num could be anything
    // 0b11010101
    // 0b11111100

    // 0b11010101 >> 2 ==
    // 0b00110101

    // 0b11010101 &
    // 0b00000001 ==
    // 0b00000001 

    // 0b11111100 & 
    // 0b00000001 ==
    // 0b00000000

    // want the middle 4 bitsit of an 8 bit number
    // maskt: 0b00111100

    // or a longer but often useful way to do this!
    // 0b11110100 << 2 ==
    // 0b11010000

    // 0b11010000 >> 4 ==
    // 0b00001101

    // 0b00001101 << 2 ==
    // 0b00110100

    
    printf("0b");
    for (int i = 0; i < 8; i++) {
        if (num >> (7 - i) & 1 == 1) {
            printf("1");
        } else {
            printf("0");
        }
    }

    printf(", 0%03o, 0x%02X\n", num, num);

}