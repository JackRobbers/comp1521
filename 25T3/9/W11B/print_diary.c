#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

int main(void) {
    // get $HOME/.diary and print the contents
    char path[MAX];
    // sprintf is vulnerable to buffer overflows, use snprintf instead
    sprintf(path, "%s/.diary", getenv("HOME"));

    char line[MAX];
    FILE *f = fopen(path, "r");
    if (f == NULL) {
        perror(path);
        return 1;
    }
    while (fgets(line, MAX, f) != NULL) {
        fputs(line, stdout);
    }
}