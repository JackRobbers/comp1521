// count the number of utf8 codepoints in a string

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int byte = 0;
    int count = 0;
    while (argv[1][byte] != 0) {
        unsigned char first = argv[1][byte];
        printf("%d %02X\n", count, first);
        if ((first & 0b10000000) == 0) {
            byte++;
        } else if ((first & 0b11100000) == 0b11000000) {
            byte += 2;
        } else if ((first & 0b11110000) == 0b11100000) {
            byte += 3;
        } else if ((first & 0b11111000) == 0b11110000) {
            byte += 4;
        } else {
            fprintf(stderr, "malformed unicode\n");
            exit(1);
        }
        count++;
    }
    printf("There were %d codepoints in the string, taking up %d bytes\n", count, byte);

    return 0;
}