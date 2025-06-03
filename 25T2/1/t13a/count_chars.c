#include <stdio.h>

// read chars until ctrl-d.
// then print how many there were
// use getchar

int main(void) {

    int count = 0;
    int c;
    while ((c = getchar()) != EOF) {
        count++;
    }

    printf("You typed %d chars\n", count);

    return 0;
}