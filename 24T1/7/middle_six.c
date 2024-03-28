#include <stdint.h>
#include <stdio.h>

uint32_t six_middle_bits(uint32_t);

int main(void) {
    return 0;
}

// x is either 0 or 1, we don't care about it
// m is either 0 or 1, we want to preserve it's value
// 0bxxxx xxxx xxxx xxxx xxxx xxxx xxxx xmmm mmmx xxxx xxxx xxxx xxxx xxxx xxxx xxxx
// 0b0000 0000 0000 0000 0000 0000 0000 0xxx xxxx xxxx xxxx xxxx xxxx xxxx xxmm mmmm
// 0b0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 00mm mmmm
uint32_t six_middle_bits(uint32_t bits) {
    bits = bits >> 29;
    // bitmask
    // 0000 .. 0011 1111
    // 0x3F
    bits = bits & 0x3F;
    return bits;
}