// write a line from stdin to argv[1]
// all error checking
// expect exactly 1 command line argument


#include <stdio.h>

#define LENGTH 1024
int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 2) {
        fprintf(stderr, "Wrong number of args, expected one filename only\n");
        return 1;
    } 
    
    FILE *file = fopen(argv[1], "a");
    if (file == NULL) {
        perror(argv[1]);
        return 1;
    }

    // if the code gets to here:
    // there is only 1 argument
    // that argument is a valid file and we have pointer to it

    char line[LENGTH];
    if (fgets(line, LENGTH, stdin) == NULL) {
        fprintf(stderr, "Didn't type anything\n");
        return 1;
    }

    fputs(line, file);

    return 0;
}