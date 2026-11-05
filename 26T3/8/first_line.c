// get the first line from argv[1]
// print it out
// all the error checking
// only allow 1 filename
// usage: ./first_line file

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
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror(argv[1]);
        return 1;
    }

    // get the line
    char line[LENGTH];
    if (fgets(line, LENGTH, file) == NULL) {
        fprintf(stderr, "File is empty\n");
        return 1;
    }

    // print the first line
    fputs(line, stdout);
    fseek(file, -10, SEEK_END);
    if (fgets(line, LENGTH, file) == NULL) {
        fprintf(stderr, "File is empty\n");
        return 1;
    }

    // print the first line
    fputs(line, stdout);

    return 0;
}