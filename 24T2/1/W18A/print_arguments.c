#include <stdio.h>

// since spec is unclear make this easily changeable
#define START 1

int main(int argc, char *argv[]) {
    for (int i = START; i < argc; i++) {
        printf("%s\n", argv[i]);
    }
    return 0;
}