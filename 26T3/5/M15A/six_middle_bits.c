#include <stdio.h>
#include <stdint.h>

uint32_t six_middle_bits(uint32_t num) {
    // 32 bits. 
    // 16  16
    // 13 6 13
    // 13 * 0, 6 * 1, * 13 * 0

    return num & (0b111111 << 13);
}

int main(void){
    printf("%08X\n", six_middle_bits(0xFFFFFFFF));
    printf("%08X\n", six_middle_bits(0xF0F0F0F0));
}

// FFFFFFFF
// FF -> 1111 1111
// 7 E -> 0111 1110