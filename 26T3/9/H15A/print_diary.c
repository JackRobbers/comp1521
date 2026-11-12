#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    char *home = getenv("HOME");
    char *path = strcat(home, "/.diary");

    printf("%s\n", path);
    FILE *f = fopen(path, "r");
    char line[1024];
    while (fgets(line, 1024, f) != NULL) {
        puts(line);
    }
}