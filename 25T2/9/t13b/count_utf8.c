// count the number of unicode codepoints in argv[1]
// assuming all valid unicode

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int byte = 0;

    int count = 0;
    while (argv[1][byte] != 0) {
        if (argv[1][byte] >> 7 == 0) {
            byte++;
        } else if ((argv[1][byte] & 0b11100000) == 0b11000000) {
            byte += 2;
        } else if ((argv[1][byte] & 0b11110000) == 0b11100000) {
            byte += 3;
        } else if ((argv[1][byte] & 0b11111000) == 0b11110000) {
            byte += 4;
        } else {
            fprintf(stderr, "invalid!!!\n");
            exit(1);
        }
        count++;
    }
    
    printf("%d bytes, %d codepoints/characters\n", byte, count);

    return 0;
}