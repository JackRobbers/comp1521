// find the file $HOME/.diary and print it

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    // c won't resolve environment vars,
    // need getenv
    char *home_path = getenv("HOME");
    int length = strlen(home_path) + 8;
    char *filename = malloc(length); 
    snprintf(filename, length, "%s/.diary", home_path);
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror(filename);
        exit(1);
    }

    int byte;
    while ((byte = fgetc(file)) != EOF) {
        fputc(byte, stdout);
    }
}