#include <stdio.h>

typedef unsigned int Word;
Word reverseBits(Word w);

int main(void) {
    printf("%x\n", reverseBits(0x01234567));
}

Word reverseBits(Word w) {
    Word reversed = 0;
    for (int i = 0; i < 32; i++) {
        // gives you each bit
        int bit = w >> i & 1;
        reversed = reversed | (bit << (31 - i));
    }


    return reversed;
}