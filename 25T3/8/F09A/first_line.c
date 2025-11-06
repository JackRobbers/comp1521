// open a file, from argv[1]
// print the first line
// error check 

#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 2) {
        printf("Wrong number of arguments\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening %s: %s\n", argv[1], strerror(errno));
        return 1;
    }

    char line[1024];
    fgets(line, 1024, file);
    printf("%s", line);


    return 0;
}