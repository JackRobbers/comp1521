#include <stdio.h>
#define MAX_LENGTH 10

int main(void) {
    char str[MAX_LENGTH];
    str[0] = 'H';
    str[1] = 'i';
    printf("My message is: %s\n", str);
    return 0;
}