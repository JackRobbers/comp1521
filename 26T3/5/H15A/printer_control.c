#include <stdint.h>
#include <stdio.h>

uint8_t printerControl = 0; // 0b 0000 0000

// Whether the printer is out of ink
#define NO_INK (0x1)       // 0b 0000 0001
// Whether to print/scan in colour
#define COLOUR (0x2)       // 0b 0000 0010
// Select print mode
#define SELECT_PRINT (0x4) // 0b 0000 0100
// Select scan mode
#define SELECT_SCAN (0x8)  // 0b 0000 1000
// Start print/scan
#define START (0x10)       // 0b 0001 0000

void has_ink() {
    // x's don't effect the output
    // printerControl =
    // case 1: 0b000xxxx0 -> 0b00000001
    // case 2: 0b000xxxx1 -> 0b00000000

    // 0b0101 &
    // 0b0011 =
    // 0b0001

    // and for masking off / isolating values

    // 0b000xxxx0 &
    // 0b00000001 =
    // 0b00000000

    // 0b000xxxx1 &
    // 0b00000001 =
    // 0b00000001

    if (printerControl & NO_INK) {
        printf("No ink\n");
    } else {
        printf("Has ink\n");
    }
}

void replace_ink() {
    // don't change the x's
    // input:  0b000xxxx1
    // output: 0b000xxxx0


    // a way to turn off / clear a bit
    // use & ~

    // 0b000xxxx1 &
    // 0b11111110 =
    // 0b000xxxx0

    // ~0b11111110 =
    //  0b00000001


    printerControl = printerControl & ~NO_INK;
}

void select_scan_and_colour() {
    // preserve xs
    // input:  0b000x0x0x
    // output: 0b000x1x1x

    // or turns bits on

    // 0b0101 |
    // 0b0011
    // 0b0111

    // 0b000x0x0x |
    // 0b00001010 =
    // 0b000x1x1x

    printerControl = printerControl | COLOUR | SELECT_SCAN;
}

void toggle_print_scan() {
    // case 1: 0b000x01xx -> 0b000x10xx
    // case 2: 0b000x10xx -> 0b000x01xx

    // xor toggles

    // 0b0101 ^
    // 0b0011
    // 0b0110

    // 0b000x01xx ^
    // 0b00001100 =
    // 0b000x10xx

    // 0b000x10xx ^
    // 0b00001100 =
    // 0b000x01xx

    printerControl = printerControl ^ (SELECT_PRINT | SELECT_SCAN);
}

int main(void) {
    has_ink();

    printerControl = NO_INK;
    printf("set the state to NO_INK\n");
    has_ink();
}