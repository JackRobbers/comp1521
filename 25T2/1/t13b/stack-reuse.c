#include <stdio.h>
#include <stdlib.h>

int *get_num_ptr();

int main(void) {
    int *num = get_num_ptr();
    printf("%d\n", *num);

    free(num);
}

int *get_num_ptr() {
    int *x = malloc(sizeof(int));
    *x = 42;
    return x;
}