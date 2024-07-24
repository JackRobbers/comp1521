// search either in stdin or files
// argv[1] is the string to search for
// argv[2...] is optional and are filenames to look in
// if only the string is given, look at stdin

#include <stdio.h>
#include <string.h>
#include <errno.h>  
#include <stdlib.h>

#define MAX 1024

void search(FILE *file, char *name, char *search);

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("%s usage: %s SEARCH [files...]\n", argv[0], argv[0]);
    } else if (argc == 2) {
        // look at stdin
        search(stdin, "<stdin>", argv[1]);
    } else {
        // look at each of the given files.
        for (int i = 2; i < argc; i++) {
            FILE *file = fopen(argv[i], "r");
            if (file == NULL) {
                // error handling
                perror(argv[i]);
                exit(1);

                // similar but with more control:
                // error = strerror(errno);
                // printf("Error was %s\n", error);
            }
            search(file, argv[i], argv[1]);
        }
    }
    
    return 0;
}

// given a file, find any occurances of the search string
// and print them out.
void search(FILE *file, char *name, char *search) {
    // check each line for the search term
    int line_number = 0;
    char line[MAX];
    while (fgets(line, MAX, file) != NULL) {
        // strstr check's if search is a substring of line
        if (strstr(line, search) != NULL) {
            // if the line contains "search", print it out with a filename
            // and line number attached
            printf("%s on line %d: %s", name, line_number, line);
        }
        line_number++;
     }
}