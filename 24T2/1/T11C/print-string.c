#include <stdio.h>
#define MAX_LENGTH 10

int main(void) {
    char str[3];
    str[0] = 'H';
    str[1] = 'i';
    str[2] = '\0';

    printf("My message is: %s\n", str);
    return 0;
}