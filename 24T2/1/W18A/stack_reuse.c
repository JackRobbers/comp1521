#include <stdio.h>
#include <stdlib.h>

int *get_num_ptr(void);

int main(void) {
    int *num = get_num_ptr();
    // other code in here could potentially change *num
    printf("%d\n", *num);
    free(num);
}

int *get_num_ptr(void) {
    int *p = malloc(sizeof(int));
    *p = 42;
    return p;
}