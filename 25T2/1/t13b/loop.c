#include <stdio.h>

int main(void) {
    int i = 0;
    while (i < 10) {
        printf("%d\n", i);
        i++;
    }
    printf("final i was %d\n", i);
    return 0;
}

// for version
int main(void) {
    int i = 0;
    for (; i < 10; i++) {
        printf("%d\n", i);
    }

    printf("final i was %d\n", i);
}
