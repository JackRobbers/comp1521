// given a file on command line, open it and print the first line
// error if number of args is wrong, or issues opening file

#include <stdio.h>
#include <errno.h>
#include <string.h>

#define MAX 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./first_line filename\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL) {
        // perror(argv[1]);
        char *error = strerror(errno);
        printf("Error '%s' when opening file '%s'\n", error, argv[1]);
    } else {
        char line[MAX];
        fgets(line, MAX, file);
        fputs(line, stdout);
    }

    fclose(file);

    return 0;
}