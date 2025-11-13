#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *unicode = argv[1];

    int codepoints = 0;
    int i = 0;
    while (unicode[i] != '\0') {
        if (unicode[i] >> 7 == 0) {
            i += 1;
        } else if ((unicode[i] & 0b1110000) == 0b11000000) {
            i += 2;
        } else if ((unicode[i] & 0b11110000) == 0b11100000) {
            i += 3;
        } else if ((unicode[i] & 0b11111000) == 0b11110000) {
            i += 4;
        }

        codepoints++;
    }

    printf("%d codepoints, %d bytes\n", codepoints, i);
}