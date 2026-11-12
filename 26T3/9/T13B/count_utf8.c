// print the number of codepoints in argv[1]
// assume that all codepoints are valid utf8
#include <stdio.h>

int main(int argc, char *argv[]) {
    // count chars
    char *string = argv[1];
    int bytes = 0;
    int codepoints = 0;
    while (string[bytes] != '\0') {
        if ((string[bytes] & 0b10000000) == 0) {
            bytes++;
        } else if ((string[bytes] & 0b11100000) == 0b11000000) {
            bytes += 2;
        } else if ((string[bytes] & 0b11110000) == 0b11100000) {
            bytes += 3;
        } else if ((string[bytes] & 0b11111000) == 0b11110000) {
            bytes += 4;
        }
        codepoints++;
    }

    printf("There were %d bytes and %d codepoints in the string\n", bytes, codepoints);
}