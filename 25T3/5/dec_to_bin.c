// take in a decimal number, output it in binary

#include <stdio.h>
#include <stdint.h>


int main(void) {
    uint8_t num;
    scanf("%hhd", &num);

    // and lets you check if bits are set -> masking 
    // 0b00001011 & 
    // 0b00000010 ==
    // 0b00000011

    // 0b11110111 & 
    // 0b00001111 ==
    // 0b00000111
    // just want the lower 4 bits

    // (0b11110111 << 4) >> 4 == 
    // (0b01110000) >> 4 == 
    // (0b00000111)

    // or lets you combine bits togther
    // 0b00001011 | 
    // 0b11000010 ==
    // 0b11001011

    // 0b10001100 << 2 ==
    // 0b00110000

    // 0b10001101 >> 2 ==
    // 0b00100011


    // toggle bits with xor
    // 0b00001011 ^
    // 0b11000010 ==
    // 0b11001001

    // 0b00000111 ^
    // 0b00000010 == 
    // 0b00000101
    // then use the same mask
    // 0b00000101 ^
    // 0b00000010 == 
    // 0b00000111

    // 0b10101011 & 
    // 0b00000001 == 
    // 0b00000001

    // 0b00101010 & 
    // 0b00000001 == 
    // 0b00000000

    // ~0b11010111 ==
    //  0b00101000

    // negate is useful e.g for turning stuff off

    // ~0b00000001 ==
    //  0b11111110
    
    // 0b00010011 & 
    // 0b11111110 ==
    // 0b00010010


    // say the that the ink has been replaced
    // printControl = printerControl & ~NO_INK

    // to use colour and select scan mode. Assume no mode has been selected yet
    // printerControl = printerControl | COLOUR | SCAN

    // toggle print and scan
    // 0b00001000 ^ (PRINT | SCAN) ==
    // 0b00000100

    // 0b00000100 ^ (PRINT | SCAN) ==
    // 0b00001000



    printf("0b");
    for (int i = 0; i < 8; i++) {
        if (num >> (7 - i) & 0b00000001) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
}