#include <stdio.h>
#include <math.h>

int main(void) {
    float a = 10.0;
    while (a < INFINITY) {
        a *= a;
        printf("%f\n", a);
    }

    float too_big = 100000000000.0;

    printf("%f %f", too_big, too_big + 1);
    return 0;
}