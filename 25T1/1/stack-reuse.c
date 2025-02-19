#include <stdio.h>
#include <stdlib.h>

int get_num(void);

int main(void) {
    int num = get_num();
    // other code in here could potentially change *num
    printf("%d\n", num);
}

int get_num(void) {
    return 42;
}