#include <stdio.h>

int *get_num_ptr(void);

int main(void) {
    int *num = get_num_ptr();
    int *num2 = get_num_ptr();
    *num2 = 10;
    // other code in here could potentially change *num
    printf("%d\n", *num);
}

int *get_num_ptr(void) {
    int x = 42;
    return &x;
}