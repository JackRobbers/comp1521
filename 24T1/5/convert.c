#include <stdio.h>

int main(void) {
    printf("Enter a number: ");

    int num;
    scanf("%i", &num);

    printf("%d = 0b", num);
    for (int shift = 7; shift >= 0; shift--) {
        printf("%d", num >> shift & 1);
    }

    printf(" = 0%03o = 0x%02x\n", num, num);
    return 0;
}