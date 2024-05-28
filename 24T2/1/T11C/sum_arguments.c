// assuming all arguments are numerical

#include <stdio.h>
#include <stdlib.h>

#define ZERO 0

int main(int argc, char *argv[]) {
    int sum = ZERO;
    printf("argc is: %d\n", argc);
    for (int i = 1; i < argc; i++) {
        sum += atoi(argv[i]);
    }
    printf("%d\n", sum);
}