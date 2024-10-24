#include <stdio.h>

int main(void) {
    printf("Enter a number: ");

    int num;
    // %i takes input as decimal, octal, or hex. (binary not supported)
    scanf("%i", &num);
    printf("%d = 0b%08b = 0%03o = 0x%02x\n", num, num, num, num);

    return 0;
}

// code for doing this without %b
// printf("%d = 0b", num);
// for (int shift = 7; shift >= 0; shift--) {
//     printf("%d", num >> shift & 1);
// }