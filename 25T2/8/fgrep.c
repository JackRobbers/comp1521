// search in the given file(s)
// if no file given search stdin
// print out all lines that match
// usage ./fgrep search_term [files...]

#include <stdio.h>
#include <string.h>

#define MAX 1024

void search(char *search, FILE *file);

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("usage: ./fgrep search_term [files...]\n");
    } else if (argc == 2) {
        // search stdin
        search(argv[1], stdin);
    } else {
        // search each file
        for (int i = 2; i < argc; i++) {
            FILE *file = fopen(argv[i], "r");
            search(argv[1], file);
        }
    }

    return 0;
}

// print each line of the file that contains search
void search(char *search, FILE *file) {
    char line[MAX];
    int line_number = 1;
    while (fgets(line, MAX, file) != NULL) {
        if (strstr(line, search) != NULL) {
            printf("%d: %s", line_number, line);
        }
        line_number++;
    }
}