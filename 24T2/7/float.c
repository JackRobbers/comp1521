#include <stdio.h>
#include <math.h>

int main(void) {
    float a = 2.0;

    while (a < INFINITY) {
        a = -a / 0;

        printf("%f\n", a);
    }

    return 0;
}