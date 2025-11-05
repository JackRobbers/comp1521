// print the first line of a file

// If given an incorrect number of arguments, or if there was an error opening the file, it should print a suitable error message. 

#include <string.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    // argv[1] should be a filename
    if (argc > 2 || argc < 2) {
        printf("Wrong number of arguments\n");
        return 1;
    }

    // we must have a filename
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        // perror(argv[1]);

        printf("the error was: %s when opening %s", strerror(errno), argv[1]);
        return 1;
    }

    char line[1024];
    fgets(line, 1024, file);
    printf("%s", line);

    fclose(file);

    return 0;
}