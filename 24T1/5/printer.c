#include <stdint.h>
#include <stdio.h>

uint8_t printer_control = 1;

#define NO_INK 0x1
#define COLOUR 0x2
#define SELECT_PRINT 0x4
#define SELECT_SCAN 0x8
#define START 0x10

void check_ink(void) {
    if (printer_control & NO_INK) {
        printf("No ink!\n");
    } else {
        printf("Has ink!\n");
    }
}

void replace_ink(void) {
    printer_control &= ~NO_INK;
}

void swap_print_scan(void) {
    printer_control ^= SELECT_PRINT | SELECT_SCAN
}

int main(void) {
    check_ink();
    replace_ink();
    check_ink();


}