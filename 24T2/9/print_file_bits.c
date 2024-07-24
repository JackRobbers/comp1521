// read in 32 bit number in hex
// from a text file
// convert the least significant BYTE
// to an 8 bit signed number

#include <stdlib.h>
#include <stdio.h>

#define MAX 1024

// assume a single file as input
int main(int argc, char *argv[]) {
    FILE *file = fopen(argv[1], "r");

    char line[MAX];
    int bytes;
    int last_byte;
    while (fgets(line, MAX, file) != NULL) {
        sscanf(line, "%x", &bytes);
        last_byte = bytes & 0xFF;
        
        // check if the msb is a 1.
        if (bytes >> 31 & 1) {
            // a negative number
            // last byte looks like 0x000000XX
            last_byte = last_byte | 0xFFFFFF00;
        }
        printf("%x %d\n", last_byte, last_byte);
    }

    return 0;
}