// given 1 file as a command line argument, open it and print the first line
// print out all errors
// assume lines under a certain. 

#define LINE_LENGTH 1024

#include <stdio.h>
#include <string.h>
#include <errno.h>

int errno;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Not enough arguments\n");
    } else {
        FILE *file = fopen(argv[1], "r");
        if (file != NULL) {
            char line[LINE_LENGTH];
            
            fgets(line, LINE_LENGTH, file);
            printf("%s", line);
        } else {
            fprintf(stderr, "Error in %s, %s\n", argv[1], strerror(errno));
            // perror(argv[1]);
        }

    }


}