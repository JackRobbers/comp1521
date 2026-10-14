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
#define START (0x10)  

void has_ink() {
    // case 1: 0b000xxxx0 -> True
    // case 2: 0b000xxxx1 -> False


    // mask off what we don't care about

    // 0b000xxxx0 & 
    // 0b00000001 
    // 0b00000000

    // 0b000xxxx1 & 
    // 0b00000001
    // 0b00000001

    if (printerControl & NO_INK) {
        printf("no ink\n");
    } else {
        printf("has ink\n");
    }
}

void replace_ink() {
    
    // input:  0b000xxxx1
    // output: 0b000xxxx0
    // want each x to stay the same

    // clear out the NO_ink bit

    // 0b000xxxx1 &
    // 0b11111110 =
    // 0b000xxxx0


    // negate
    // ~0b00000001 =
    //  0b11111110

    printerControl = printerControl & ~NO_INK;
}

void select_scan_and_colour() {
    // make the scan and colour bits 1

    // input:  0b000x0x0x
    // output: 0b000x1x1x

    // 0b000x0x0x |
    // 0b00001010
    // 0b000x1x1x

    // or to turn bits on
    printerControl |= SELECT_SCAN | COLOUR;
    // same as: printerControl = printerControl | SELECT_SCAN | COLOUR;
}

void toggle_print_and_scan() {
    // case 1: 0b000x01xx -> 0b000x10xx
    // case 2: 0b000x10xx -> 0b000x01xx

    // xor: toggle masked bits

    // 0b000x01xx ^
    // 0b00001100 =
    // 0b000x10xx

    // 0b000x10xx ^
    // 0b00001100 = 
    // 0b000x01xx

    // 0b0101 ^
    // 0b0011
    // 0b0110

    printerControl ^= SELECT_PRINT | SELECT_SCAN;
}