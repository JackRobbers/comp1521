#include <stdio.h>
#include <stdlib.h>

// argv[2] is the byte
// argv[3] is where to write it

int main(int argc, char *argv[]) {

        FILE *file = fopen(argv[1], "r+");


        if (file == NULL) {
                perror(argv[1]);
                return 1;
        }

        // SEEK_SET -> a specific spot
        // SEEK_CUR
        // SEEK_END
        fseek(file, atoi(argv[3]), SEEK_SET);
        printf("at position: %ld\n", ftell(file));
        fputc(atoi(argv[2]), file);
}