// read files from command line args

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX 1024

void print_file_bits(char *filename);

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        print_file_bits(argv[i]);
    }
}

void print_file_bits(char *filename) {
    // print the least significant byte as signed 8 bit;

    FILE *file = fopen(filename, "r");

    char line[MAX];
    while (fgets(line, MAX, file) != NULL) {
        long number = strtol(line, NULL, 16);
        // grab the last 2 digits / the last byte
        int converted = number & 0xFF;
        
        // do sign extension, if 8th bit is 1
        if (converted >> 7 & 1) {
            converted = converted | 0xFFFFFFF00;
        }
        
        printf("0x%08X\n", converted);
        printf("%d\n", converted);
        

        // turn into int


    }


}