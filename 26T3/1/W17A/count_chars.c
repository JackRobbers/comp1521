#include <stdio.h>

// read chars until ctrl-d / EOF.
// then print how many there were
// also print the chars
// getchar
int main(void) {
    int count = 0;
    int c;
    // stop when there is no input 
    while ((c = getchar()) != EOF) {
        putchar(c);
        count++;
    }

    printf("You typed %d chars\n", count);
    
    return 0;
}