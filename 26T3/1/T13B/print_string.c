#include <stdio.h>
#define STR_LEN 3

int main(void) {
    char str[STR_LEN];
    str[0] = 'H';
    str[1] = 'i';
    str[2] = '\0';

    char *spot_me = "hello";

    char other_string[STR_LEN];
    other_string[0] = '!';
    
    printf("%s\n", str);
    return 0;
}