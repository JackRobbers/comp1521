#include <stdio.h>
#include <stdint.h>

union both {
    uint32_t integer_value;
    float float_value;
};

int main(void) {
    union both a;
    scanf("%f", &a.float_value);

    int sign = (a.integer_value >> 31) & 1;
    printf("%f %d\n", a.float_value, a.integer_value);
    printf("float has sign %d\n", sign);
    return 0;
}