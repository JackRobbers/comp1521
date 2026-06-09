#include <stdio.h>

// read chars until ctrl-d. -> EOF
// use getchar -> 
// then print how many there were

int main(void) {
    int c;
    int count;
    while ((c = getchar()) != EOF) {
        count++;
    }

    printf("There were %d chars\n", count);
    
    return 0;
}