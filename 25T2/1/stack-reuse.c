#include <stdio.h>
#include <stdlib.h>

int get_num(void);
int *get_num_ptr(void);

int main(void) {
    int *num = get_num_ptr();
    printf("%d\n", *num);
}

// why is it even a pointer
int get_num(void) {
    return 42;
}

// use malloc
int *get_num_ptr(void) {
    int *x = malloc(sizeof(int));
    *x = 42;
    return x;
}

// original
int *get_num_ptr(void) {
    int x = 42;
    return &x;
}