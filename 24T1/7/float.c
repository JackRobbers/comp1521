#include <stdio.h>
#include <math.h>

int main(void) {
    float a = 10.0;
    while (a < INFINITY) {
        a *= a;
        printf("%f\n", a);
    }
    return 0;
}