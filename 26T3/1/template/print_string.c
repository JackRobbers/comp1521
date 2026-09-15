#include <stdio.h>
#define STR_LEN 10

int main(void) {
    char str[STR_LEN];
    str[0] = 'H';
    str[1] = 'i';
    
    printf("%s", str);
    return 0;
}