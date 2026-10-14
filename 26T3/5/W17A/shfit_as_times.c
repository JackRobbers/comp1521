#include <stdint.h>
#include <stdio.h>

int main(void) {

    uint8_t num = 3;

    for (int i = 0; i < 5; i++) {
        printf("%d\n", num << i);
    }

}