#include <stdint.h>
#include <stdio.h>

uint8_t printerControl = 1; // 0b 0000 0000

// Whether the printer is out of ink
#define NO_INK (0x1)       // 0b 0000 0001
// Whether to print/scan in colour
#define COLOUR (0x2)       // 0b 0000 0010
// Select print mode
#define SELECT_PRINT (0x4) // 0b 0000 0100
// Select scan mode
#define SELECT_SCAN (0x8)  // 0b 0000 1000
// Start pritnt/scan
#define START (0x10)       // 0b 0001 0000

void has_ink(void);
void replace_ink(void);

int main(void) {
    has_ink();
    replace_ink();
    has_ink();
}

// that prints (to terminal) whether the printer is out of ink.
void has_ink(void) {
    if (printerControl & NO_INK) {
        printf("no ink!\n");
    } else {
        printf("has ink\n");
    }
}

// that tells the printer the ink has been replaced.
void replace_ink(void) {
    // set no_ink to 0

    //  0b00011011 & ~0b00000001 == 
    //  0b00011011 &  
    //  0b11111110 == 
    //  0b00011010

    // & ~, clears the masked bits

    printerControl &= ~NO_INK;

}

// to use colour and select scan mode. Assume no mode has been selected yet.
void colour_and_scan(void) {
    // or lets you turn bits on without changing
    // surrounding bits

    // 0b00010001 | 
    // 0b00000010 == 
    // 0b00010011


    printerControl |= COLOUR;
    printerControl |= SELECT_SCAN;
}

// that toggles between print and scan mode. Assume 1 mode is alrteady selected.
void toggle_print_and_scan(void) {
    // xor lets you toggle bits  
   
    // e.g in print mode
    // 0b00010111 ^
    // 0b00001100 ==
    // 0b00011011

    // toggle back
    // 0b00011011 ^
    // 0b00001100 ==
    // 0b00010111

    printerControl ^= (SELECT_PRINT | SELECT_SCAN);
}

// (Extension question) to start printing/scanning. It should:
//     check that one (and only one) mode is selected
//     check there's ink if printing.
//     print (to terminal) what it's doing and any error messages.
//     wait until the printing/scanning is finished and print a 'finished' message. Since there isn't an actual printer on the other side, a correct implementation of this will infinite loop and never print 'finished'.
