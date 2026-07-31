// take in unicode codepoints as argv[1]
// print the number of codepoints and bytes

#include <stdio.h>

int main(int argc, char *argv[]) {
        char *unicode = argv[1];

        int codepoints = 0;
        int i = 0;

        unsigned char current = unicode[i];
        while (current != '\0') {
                if ((current & 0b10000000) == 0) {
                        i++;

                } else if ((current & 0b11100000) == 0b11000000) {
                        i += 2;
                } else if ((current & 0b11110000) == 0b11100000) {
                        i += 3;
                } else if ((current & 0b11111000) == 0b11110000) {
                        i += 4;
                } else {
                        printf("should never happen %X\n", current);
                }

                current = unicode[i];
                codepoints++;

        }

        printf("codepoints: %d, bytes: %d\n", codepoints, i);
}