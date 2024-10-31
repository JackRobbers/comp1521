#include <stdio.h>
#include <string.h>
#include <errno.h>

#define MAX 1024

int errno;

void search(FILE *file, char *search_for, char *file_name);

// search the contents of files
// thing to search for is the first argument
// arguments after that are files to look in
// if no files given, look at stdin

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "usage: fgrep search, [file1, file2, ...]\n");
    } else if (argc == 2) {
        // search stdin
        search(stdin, argv[1], "stdin");
    } else {
        // seach each file
        for (int i = 2; i < argc; i++) {
            FILE *file = fopen(argv[i], "r");
            if (file == NULL) {
                //perror("Failed to open file");
                printf("Error \"%s\" when opening %s\n", strerror(errno), argv[i]);
            } else {
                search(file, argv[1], argv[i]);
            }
        }
    }
}

void search(FILE *file, char *search_for, char *file_name) {
    // get the contents of the file, line by line
    char line[MAX];
    int line_number = 1;
    while (fgets(line, MAX, file) != NULL) {
        // strstr checks if line contains search_for
        if (strstr(line, search_for) != NULL) {
            printf("found on line %d in %s: %s", line_number, file_name, line);
        }
        line_number++;
    }   
}