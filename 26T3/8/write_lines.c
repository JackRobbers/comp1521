// write lines of input from stdin to argv[1].
// stop when ctrl-d

#include <stdio.h>

#define LENGTH 1024

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Not enough args\n");
        return 1;
    } else if (argc > 2) {
        fprintf(stderr, "Too many args\n");
        return 1;
    }

    // open the file
    FILE *file = fopen(argv[1], "w");
    if (file == NULL) {
        perror(argv[1]);
        return 1;
    }

    char line[LENGTH];
    // get lines of input
    while (fgets(line, LENGTH, stdin) != NULL) {
        fputs(line, file);
    }

    return 0;
}