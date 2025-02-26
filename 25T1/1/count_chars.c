#include <stdio.h>

// read chars until ctrl-d.
// then print how many there were

int main(void) {
    int count = 0;
    while (getchar() != EOF) {
        count++;
    }

    printf("count: %d\n", count);

    return 0;
}