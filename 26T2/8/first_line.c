#include <stdio.h>

#define SIZE 1024

// print the first line of argv[1]

int main(int argc, char *argv[]) {

        if (argc != 2) {
                fprintf(stderr, "Didn't get exactly 1 path\n");
                return 1;
        }

        FILE *file = fopen(argv[1], "r");
        if (file == NULL) {
                perror(argv[1]);
                return 1;
        }

        char string[SIZE];
        if (fgets(string, SIZE, file) == NULL) {
                fprintf(stderr, "Empty or invalid file\n");
                return 1;
        }

        if (fputs(string, stdout) == EOF) {
                fprintf(stderr, "Empty or invalid file\n");
                return 1;
        }

        return 0;
}