#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    unsigned char *unicode = argv[1];

    int i = 0;
    int bytes = strlen(unicode);
    int codepoints = 0;
    while (i < bytes) {
        // assuming all valid unicode
        // printf("%d %d %x\n", i, bytes, unicode[i]) ;

        if ((unicode[i] >> 7) == 0) {
            i += 1;
        } else if ((unicode[i] & 0xE0) == 0xC0) {
            i += 2;
        } else if ((unicode[i] & 0xF0) == 0xE0) {
            i += 3;
        } else if ((unicode[i] & 0xF8) == 0xF0) {
            i += 4;
        }

        codepoints++;
    }

    printf("codepoints: %d, bytes: %d\n", codepoints, bytes);
}