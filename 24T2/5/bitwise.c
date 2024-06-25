#define READING   0x01
#define WRITING   0x02
#define AS_BYTES  0x04
#define AS_BLOCKS 0x08
#define LOCKED    0x10

unsigned char device = 0; // 8 bit integer 0b00000000

// mark the device as locked for reading bytes
device = device | READING | LOCKED;
// 0bxxx1xxx1

// mark the device as locked for writing blocks
device = device | WRITING | LOCKED
// 0bxxx1xx1x
device = WRITING | LOCKED
// 0b00010010

device = 0;

// set the device as locked, leaving other flags unchanged
device = device | LOCKED;
// 0bxxx1xxxxx
device = LOCKED;
// 0b000010000

device = 0b00010001;
// remove the lock on a device, leaving other flags unchanged
device = device & ~LOCKED
// equivalent, since we know the lock is set
device = device ^ LOCKED

// device is 0bxxxxxx01
// switch a device from reading to writing, leaving other flags unchanged
device ^ (WRITING | READING)
// 0bxxxxxx10

// swap a device between reading and writing, leaving other flags unchanged
device ^ (WRITING | READING)

// if I need n 1s. do 2^n - 1
// for 4 1s. 15. 0XFF
// 0b1111