#include <stdio.h>
#define STR_LEN 10

int main(void) {
    char str[STR_LEN];
    str[0] = 'H';
    str[1] = 'i';
    str[2] = '\0';     char str2[2];
    str2[0] = '!';
    
    printf("%s\n", str);
    return 0;
}