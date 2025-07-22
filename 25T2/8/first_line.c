// open the file given and print first line
// throw errors on wrong number of args or issues with opening file

#include <stdio.h>
#include <string.h>
#include <errno.h>

#define MAX 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./first_line [file_name]\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL) {
        // perror(argv[1]);

        char *error = strerror(errno);
        printf("Couldn't open file '%s', with error '%s'\n", argv[1], error);
    } else {
        char line[MAX];
        fgets(line, MAX, file);

        fputs(line, stdout);
    }

    return 0;
}