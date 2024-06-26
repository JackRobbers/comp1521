#include <stdint.h>

#define READING   0x01 // 0b00000001
#define WRITING   0x02 // 0b00000010
#define AS_BYTES  0x04 // 0b00000100
#define AS_BLOCKS 0x08 // 0b00001000
#define LOCKED    0x10 // 0b00010000

uint8_t device;
// same as unsigned char device

// mark the device as locked for reading bytes, overwriting state
device = READING | LOCKED
// 0b00010001

// x represents anything / don't care
device = 0bxxxxxxxx;
// just change the specified bits, preserves state
device = device | READING | LOCKED;
// 0bxxx1xxx1

// mark the device as locked for writing blocks
// same as locked for reading blocks

// set the device as locked, leaving other flags unchanged
device = device | LOCKED;

// remove the lock on a device, leaving other flags unchanged
device = device & ~LOCKED;
// ~LOCKED = 0b11101111

// switch a device from reading to writing, leaving other flags unchanged
// swap a device between reading and writing, leaving other flags unchanged 
device = device ^ (READING | WRITING);
// READING | WRITING = 0b00000011
// device is 0bxxxxxx01 
// 0bxxxxxx01 ^
// 0b00000011 =
// 0bxxxxxx10

// device is 0bxxxxxx10
// 0bxxxxxx10 ^
// 0b00000011 = 
// 0bxxxxxx01
