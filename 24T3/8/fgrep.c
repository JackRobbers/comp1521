#include <stdio.h>
#include <string.h>

#define MAX 100

void search(char *search, FILE *file, char *filename);

// search given streams for argv[1]
// stdin if argc < 2, otherwise read from
int main(int argc, char *argv[]) {
    // argv[0] is program name
    if (argc < 2) {
        printf("error, not enough arguments\n");
    } else if (argc == 2) {
        // search stdin
        search(argv[1], stdin, "stdin");
    } else {
        // search in argv[2], argv[3], ...
        for (int i = 2; i < argc; i++) {
            FILE *file = fopen(argv[i], "r");
            if (file == NULL) {
                perror("failed to open filem");
            } else {
                search(argv[1], file, argv[i]);
            }
        }
    }
}

void search(char *search, FILE *file, char *filename) {
    char line[MAX];
    int i = 1;
    while (fgets(line, MAX, file) != NULL) {
        // line contains argv[1]
        if (strstr(line, search) != NULL) {
            printf("found on line %d in %s: %s", i, filename, line);
        };
        i++;
    }
}