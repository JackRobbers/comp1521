// search in
// usage: fgrep search [files]
// if no files are given, search stdin

#include <stdio.h>
#include <string.h>

#define LENGTH 1024

// look for lines that match
void search(FILE *file, char *string) {
    char line[LENGTH];
    int i = 1;
    while (fgets(line, LENGTH, file) != NULL) {
        // is search a substring of line
        if (strstr(line, string) != NULL) {
            printf("%d: %s", i, line);
        }
        i++;
    }
}

// argv[0] is prog_name, argv[1] is search. argv[2], argv[3]... are files
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Not enough args\n");
        return 1;
    }

    if (argc > 2) {
        for (int i = 2; i < argc; i++) {
            FILE *file = fopen(argv[i], "r");

            search(file, argv[1]);
        }
    } else {
        search(stdin, argv[1]);
    }
}