// usage: ./fgrep string [files]
// find string in files, if no file given, search stdin.

#define MAX_LENGTH 1024

#include <stdio.h>
#include <errno.h>
#include <string.h>

void search(FILE *file, char *string);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "not enough arguments\n");
    } else if (argc == 2) {
        // search stdin
        search(stdin, argv[1]);
    } else {
       
        for (int i = 2; i < argc; i++) {
            FILE *file = fopen(argv[i], "r");
            if (file != NULL) {
                search(file, argv[1]);
            } else {
                fprintf(stderr, "Error opening %s, %s\n", argv[i], strerror(errno));
            }
        }

        // search each file
    }
}

// search a file *
// assuming a text file
void search(FILE *file, char *string) {
    char line[MAX_LENGTH];
    int line_number = 1;
    while (fgets(line, MAX_LENGTH, file) != NULL) {
        if (strstr(line, string) != NULL) {
            printf("match on line %d: %s", line_number, line);
        }
        line_number++;
    }   
}