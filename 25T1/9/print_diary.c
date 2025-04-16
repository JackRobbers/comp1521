// open $HOME/.diary and print the contents

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1024

int main(void) {
    // getenv
    char *home_path = getenv("HOME");
    char *path = strcat(home_path, "/.diary");
    // open the file
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        perror("");
        return 1;
    }

    char line[MAX];
    // print the contents
    while (fgets(line, MAX, file) != NULL) {
        printf("%s", line);
    }
}