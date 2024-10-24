#include <stdint.h>
#include <stdio.h>

// printer starts with no ink
uint8_t printer_control = 1;

#define NO_INK 0x1
#define COLOUR 0x2
#define SELECT_PRINT 0x4
#define SELECT_SCAN 0x8
#define START 0x10

void check_ink(void);
void refill_ink(void);
void set_colour_and_scan(void);

int main(void) {
    check_ink();
    refill_ink();
    check_ink();
    set_colour_and_scan();
}

// x is a digit we don't care about the value
// d is a digit we want to preserve

// either
// 0bxxxxxxx1
// 0bxxxxxxx0
// so output should be
// 0b0000000d

// 0bxxxxxxx1 &
// 0b00000001 =
// 0b00000001

// 0bxxxxxxx0 &
// 0b00000001 =
// 0b00000000

// check if NO_INK is set

void check_ink(void) {
    if (printer_control & NO_INK) {
        printf("Out of ink!\n");
    } else {
        printf("has ink!\n");
    }
}

// want to refill the ink.
// set NO_INK to 0

// construct the mask with ~
//~0b00000001 = 
// 0b11111110

// & clears all bits not in the mask
// input:  0bddddddd1 
// output: 0bddddddd0
// 
// 0bddddddd1 &
// 0b11111110 =
// 0bddddddd0

// set NO_INK to 0
void refill_ink(void) {

    printer_control = printer_control & ~NO_INK;

    printf("refilled the ink!\n");
}

// set colour and scan, no mode is selected.
// 0bdddd00xd <- input
// 0bdddd101d <- output

// 0bdddd00xd |
// 0b00001010 =  <-- need to construct this mask
// 0bdddd101d


// just do | in sequence to make it!
// 0bdddd00xd |
// 0b00000010 =
// 0bdddd001d

// 0bdddd001d | 
// 0b00001000
// 0bdddd101d

void set_colour_and_scan(void) {
    printer_control = printer_control | COLOUR | SELECT_SCAN;
}