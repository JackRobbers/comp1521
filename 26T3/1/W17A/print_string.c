#include <stdio.h>
#define STR_LEN 3

int main(void) {
    char str[STR_LEN];
    str[0] = 'H';
    str[1] = 'i';
    str[2] = '\0';

    char *string = "hello";

    char str2[STR_LEN];
    str2[0] = '!';
    
    printf("%s\n", str);
    return 0;
}