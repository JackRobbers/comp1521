#include <stdint.h>
#include <stdio.h>

int main(void) {

}

uint32_t six_middle_bits(uint32_t num) {
    // 32
    // 16 16
    // 13 * 0, 6 * 1, 13 * 0 
    // 00000000 00000101 01100000 00000000 >> 13
    // 00000000 00000000 00000000 00101011

    // return (num & 0b00000000000001111110000000000000) >> 13;

    // return (num & 0x0007E000) >> 13;

    return (num >> 13) & 0b111111;
}