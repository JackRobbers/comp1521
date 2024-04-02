// search either in stdin or files
// argv[1] is the string to search for
// argv[2...] is optional and are filenames

#include <stdio.h>
#include <string.h>
#include <errno.h>  

#define MAX 1024

void search(FILE *file, char *name, char *search);

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        // throw an error if argc <= 1
        printf("need 1+ arguments\n");
    } else if (argc == 2) {
        // if argc == 2 take input from stdin
        search(stdin, "stdin", argv[1]);
    } else {
        // if argc > 2 read from files.
        for (int i = 2; i < argc; i++) {
            // open each of the files given by argv[2] .. agrv[argc]
            FILE *file = fopen(argv[i], "r");
            if (file == NULL) {
                printf("error opening file %s: %s\n", argv[i], strerror(errno));
            } else {
                // run search on them
                search(file, argv[i], argv[1]);
            }
        }

    }
    return 0;
}

// given a file, find any occurances of the search string
// and print them out.
void search(FILE *file, char *name, char *search) {
    char line[MAX];
    int line_number = 1;
    // loop through each line of the file
    while (fgets(line, MAX, file) != NULL) {
        // check if that line contains search
        if (strstr(line, search) != NULL) {
            // add the line number when printing lines
            printf("found a match in file %s on line %d: %s", name, line_number, line);
        }
        line_number++;
    }
}