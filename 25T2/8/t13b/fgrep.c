// match searches, either in stdin or files

#include <stdio.h>
#include <string.h>

#define MAX 1024

void search(char *search, FILE *file);

int main(int argc, char *argv[]) {
    if (argc == 1) {
        // not enough args
        printf("Usage ./fgrep search [FILES]");
    } else if (argc == 2) {
        // just search
        search(argv[1], stdin);
    } else {
        // file(s)
        for (int i = 2; i < argc; i++) {
            FILE *file = fopen(argv[i], "r");
            if (file == NULL) {
                perror(argv[i]);
            } else {
                search(argv[1], file);
            }
        }
    }

    return 0;
}

// look at each line, print them if they match search
void search(char *search, FILE *file) {
    char line[MAX];
    while (fgets(line, MAX, file) != NULL) {
        if (strstr(line, search) != NULL) {
            printf("match %s", line);
        }
    }
}