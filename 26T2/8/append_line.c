#include <stdio.h>

#define SIZE 1024

// append a line from stdin to the file argv[1]

int main(int argc, char *argv[]) {

        if (argc != 2) {
                fprintf(stderr, "Didn't get exactly 1 path\n");
                return 1;
        }

        FILE *file = fopen(argv[1], "a");
        if (file == NULL) {
                perror(argv[1]);
                return 1;
        }

        printf("at position: %ld\n", ftell(file));

        char string[SIZE];
        if (fgets(string, SIZE, stdin) == NULL) {
                fprintf(stderr, "Empty or invalid file\n");
                return 1;
        }

        if (fputs(string, file) == EOF) {
                fprintf(stderr, "Empty or invalid file\n");
                return 1;
        }

        return 0;
}