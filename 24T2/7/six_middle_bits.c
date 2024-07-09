// x's that we want to be 0.
// m's that we want to preserve and return
// 0b xxxxxxxx xxxxxmmm mmmmxxxxx xxxxxxxx
// 0b 000000000000000000000000000000mmmmmm

#include <stdint.h>

uint32_t six_middle_bits(uint32_t num) {
    // shift left then right
    num <<= 13;
    // mmmmmmmxx xxxxxxxx x0000000 0000000
    num >>= 26
    // 000000000000000000000000000000mmmmmm
    return num; 



    // shift right and then mask the last 6 bits
    num >>= 13;
    // 000000000000xxxxxxxxxxxxxxxxxxmmmmmm
    num &= 0b00111111; // 63 or 0x3F
    
}

int main(void) {
    // six_middle_bits(12);
}