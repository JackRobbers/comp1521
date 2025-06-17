#include <stdio.h>
#define STR_LEN 3

int main(void) {
    char str[STR_LEN];
    str[0] = 'H';
    str[1] = 'i';
    str[2] = '\0';

    // if no null terminator, gcc will print the second string
    char str2[STR_LEN];
    str2[0] = '!';
    
    printf("%s", str);
    return 0;
}