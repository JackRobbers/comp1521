#include <stdio.h>
#define STR_LEN 10

int main(void) {
    // char str[STR_LEN];
    char *str = "HI";

    char str2[STR_LEN];
    str2[0] = '!';
    printf("%s", str);
    return 0;
}