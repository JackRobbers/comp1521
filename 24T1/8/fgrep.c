// search either in stdin or files
// argv[1] is the string to search for
// argv[2...] is optional and are filenames to look in

#include <stdio.h>
#include <string.h>
#include <errno.h>  

#define MAX 1024

void search(FILE *file, char *name, char *search);

int main(int argc, char *argv[]) {
    // error when argc <= 1;
    if (argc <= 1) {
        printf("need at least 1 argument\n");
    } else if (argc == 2) {
        // search in stdin
        search(stdin, "<stdin>", argv[1]);
    } else {
        // search in each file
        for (int i = 2; i < argc; i++) {
            FILE *file = fopen(argv[i], "r");
            if (file == NULL) {
                // perror(argv[i]);
                printf("%s: %s\n", argv[1], strerror(errno));
            } else {
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
    int line_number = 0;
    while (fgets(line, MAX, file) != NULL) {
        if (strstr(line, search) != NULL) {
            printf("found a match in %s on line %d: %s",name, line_number, line);
        }
        line_number++;
    }
}