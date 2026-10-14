#include <stdint.h>
#include <stdio.h>

int main(void) {

    uint8_t num = 3;

    for (int i = 0; i < 5; i++) {
        printf("%d * 2^ %d = %d\n", num, i, num << i);
    }
    
    // 0b0000011
    // 0b0000110

    // num * 10
    // (num << 8 + num << 2)

    // 123 *
    // 103


}