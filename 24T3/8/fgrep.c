#include <stdio.h>
#include <string.h>
#include <errno.h>

#define MAX 1024

// search for strings
// if no files given, search stdin
// otherwise look in each file

// usage: ./fgrep SEARCH_TERM [file1, file2, ...]

void search(FILE *file, char *search, char *file_name);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("usage: ./fgrep SEARCH_TERM [file1, file2, ...]\n");
    } else if (argc == 2) {
        // search stdin
        search(stdin, argv[1], "stdin");
    } else {
        // search all the given 
        for (int i = 2; i < argc; i++) {
            FILE *file = fopen(argv[i], "r");
            if (file == NULL) {
                // perror(argv[i]);
                printf("error: \"%s\" for file: %s\n", strerror(errno), argv[i]);
            } else {
                search(file, argv[1], argv[i]);
            }
        }

    }
}

void search(FILE *file, char *search, char *file_name) {
    char line[MAX];
    int line_number = 1;
    // get the contents of the file
    while(fgets(line, MAX, file) != NULL) {
        // strstr tells you if line contains argv[1]
        if(strstr(line, search) != NULL) {
            printf("found \"%s\" on line %d in file %s: %s", search, line_number, file_name, line);
        }
        line_number++;
    } 
}