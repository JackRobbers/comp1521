#include <stdint.h>

// 0 is false
// 1 is true

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

uint8_t toggle_print_scan(printerControl) {
    // either in print or scan
    //

    //0bxxxx01xx
    //0bxxxx10xx
    
    //0b00001100

    //x is preserved

    return printerControl ^ (SELECT_PRINT | SELECT_SCAN);
}

// true if the printer out of ink
uint8_t out_of_ink(printerControl) {
    // 0bxxxxxxx1 => 
    // 0b00000001

    // 0bxxxxxxx0 =>
    // 0b00000000

    // 0b00010101 & 
    // 0b00000001

    return printerControl & NO_INK;
}

uint8_t replace_int(printerControl) {
    // set no_ink to 0
    // set the last bit to 0
    printerControl & ~NO_INK;

    // ~0b00000001
    // 0b11111110 
}