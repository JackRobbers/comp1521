#include <stdio.h>

// read chars until ctrl-d. -> EOF
// then print how many there were

int main(void) {
    int current;
    int count = 0;

    while ((current = getchar()) != EOF) {
        putchar(current);
        count++;
    }

    printf("You typed %d chars\n", count);

    
    return 0;
}