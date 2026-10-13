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

void out_of_ink() {
    // 0b000xxxx1
    // 0b000xxxx0

    // 0b000xxxxt &
    // 0b00000001
    // 0b0000000t

    if (printerControl & NO_INK) {
        printf("No ink\n");
    } else {
        printf("Has ink\n");
    }
}

void replace_ink() {
    // assume there is no ink

    // 0b000xxxx1 ->
    // 0b000xxxx0

    // 0b000xxxx1 &
    // 0b11111110 
    // 0b000xxxx0

    //  ~0b11111110 
    //   0b00000001
    
    // & ~ is for clearing
    // & is for masking
    printf("Replacing the ink\n");

    printerControl = printerControl & ~NO_INK;
}

void set_colour_and_scan() {
    // assuming they are both off

    // 0b000x0x0x
    // 0b000x1x1x

    // 0b000x0x0x |
    // 0b00001010 =
    // 0b000x1x1x

    // 0b00001000 | (scan)
    // 0b00000010   (colour)
    // 0b00001010

    printerControl = printerControl | SELECT_SCAN | COLOUR;    
}

void toggle_print_and_scan() {
    // assume 1 mode is already selected

    // 0b000x01xx
    // 0b000x10xx

    // ^ will toggle

    
    // xor truth table

    // 0b0101
    // 0b1100
    // 0b1001

    // 0b000x01xx ^
    // 0b00001100
    // 0b000x10xx


    // 0b000x10xx ^
    // 0b00001100
    // 0b000x01xx

    printerControl = printerControl ^ (SELECT_PRINT | SELECT_SCAN);
}

int main(void) {
    printerControl = NO_INK;

    out_of_ink();

    replace_ink();

    out_of_ink();
}