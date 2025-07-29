// print out the contents of $HOME/.diary if it exists

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char *home_path = getenv("HOME");
    int length = strlen(home_path) + 8;
    char *filename = malloc(sizeof(char) * length);
    snprintf(filename, length, "%s/.diary", home_path);

    // fopen the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror(filename);
        exit(1);
    }

    // print the contents
    int byte;
    while ((byte = fgetc(file)) != EOF) {
        fputc(byte, stdout);
    }

    return 0;
}