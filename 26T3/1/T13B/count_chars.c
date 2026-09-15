#include <stdio.h>

// read chars until ctrl-d.
// then print how many there were
// use getchar

int main(void) {
    int i = 0;
    while(getchar() != EOF) {
        i++;
    }

    printf("You typed %d chars\n", i);
    
    return 0;
}