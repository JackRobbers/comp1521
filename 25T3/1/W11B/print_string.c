#include <stdio.h>
#define STR_LEN 2

int main(void) {

    char *hi = "hello";
    char str[STR_LEN];
    str[0] = 'H';
    str[1] = 'i';

    char str2[STR_LEN];
    str2[0] = '!';
    // str[2] = '\0';
    
    printf("%s\n", str);
    return 0;
}