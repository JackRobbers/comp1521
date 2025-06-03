#include <stdio.h>

// read chars until ctrl-d.
// then print how many there were

int main(void) {
    int count = 0;
    char x;
    while ((x = getchar()) != EOF) {
        count++;
    }

    printf("You typed %d chars\n", count);
    return 0;
}