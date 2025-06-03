#include <stdio.h>
#define STR_LEN 4

int main(void) {
    char str[STR_LEN];
    str[0] = 'H';
    str[1] = 'i';
    str[2] = '\n';
    // if we leave this out, gcc will buffer overflow!
    str[3] = '\0';

    char str2[STR_LEN];
    str2[0] = '!';
 
    printf("%s", str);
    return 0;
}