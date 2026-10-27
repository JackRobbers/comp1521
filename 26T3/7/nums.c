#include <stdint.h>
#include <stdio.h>

int main(void) {


    int a = 10; // signed 4 byte number (depends on computer/architecture)

    uint8_t b = -12; // unsigned 1 byte number (0, 255)
    int8_t c = -12; // signed 1 byte number (-128, 127)

    // negative number
    // 0b00001100
    // ~(0b00001100) + 1 ==
    //  (0b11110011) + 1 ==
    //  0b11110011 +
    //  0b00000001 
// carry:      11
//   == 0b11110100
// interpretted as +
//  128 + 64 + 32 + 16 + 4 == 244

// signed bit
// 0b1 0000011 == -3
// 0b0 0000011 == 3

// 0b1 0000000 == -0
// 0b0 0000000 == +0

// 2's complement arithmetic
// -12 + 15 == 3
//      0b11110100 + 
//      0b00001111 ==
///carry: 11111  
//      0b00000011

// same to encode and decode

// 0b11110100 -> -12

// ~(0b11110100) + 1 ==
//  (0b00001011) + 1 ==
//  (0b00001100)
    printf("%d %d\n", b, c);
  
}