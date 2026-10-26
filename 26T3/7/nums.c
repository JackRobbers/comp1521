#include <stdint.h>
#include <stdio.h>

int main(void) {


    int a = 10; // signed 4 byte number (depends on computer/architecture)

    uint8_t b = -12; // unsigned 1 byte number (0, 255)
    int8_t c = -12; // signed 1 byte number (-128, 127)

    printf("%d %d\n", b, c);
    // 2's complement
    
    // -12 in 2s complement
    // first write +12
    // 0b00001100
    // negate and add 1
    // (~0b00001100) + 1 ==
    //  (0b11110011) + 1 ==
    //   0b11110100
    // interpret as unsigned:
    //   128 + 64 + 32 + 16 + 8 -> 244   
    
    // unsigned
    // check if the MSB a 0 or 1
    // if 0, it's positive
    // if 1 it's negative
    // for a negative number, apply the 2's complement transform 
    
    // ~(0b11110100) + 1
    //   0b00001011 + 1
    //   0b00001100

    // arithmetic works
    // -12 + 20 -> 8
    // 0b11110100 +
    // 0b00010100 
    // 0b00001000
}