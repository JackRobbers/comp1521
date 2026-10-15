#include <stdint.h>
#include <stdio.h>

uint32_t six_middle_bits(uint32_t four_bytes) {
    // middle 6 bits

    // turn r's to 0
    // preserve x's
    // 32
    // 16 16
    // 13 * r, 6 * x, 13 * r

    // output:
    // 26 0's. 6 x's.
    // 0b0000000000000000000xxxxxx


    // 0b01100000 >> 4 =
    // 0b00000110

    // 0b01100000 >> 6 =
    // 0b00000001
    return (four_bytes >> 13) & 0b111111;

    // 13*0's, 13 * r, 6 * x

}

int main(void) {

}
