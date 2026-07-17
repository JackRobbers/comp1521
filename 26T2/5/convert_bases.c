// take in a decimal number and output the 
// binary, octal, and hexadecimal forms

#include <stdio.h>
#include <stdint.h>

int main(void) {

    int8_t num;
    scanf("%hhd", &num);

    printf("0b");
    for (int i = 0; i < 8; i++) {
        // printf("%d", (num >> (7 -i)) & 1);

        printf("%d", (num & (1 << (7 - i))) > 0);

    }

    printf(", 0%03o, 0x%02X\n", num, num);

}