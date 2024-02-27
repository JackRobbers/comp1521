#include <stdio.h>
#define MAX_LENGTH 10

int main(void) {
    char str[10];
    str[0] = 'H';
    str[1] = 'i';
    // char str2[MAX_LENGTH];
    // str2[0] = 'J';
    printf("My message is: %s\n", str);
    return 0;
}