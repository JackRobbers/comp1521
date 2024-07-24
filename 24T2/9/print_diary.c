// read $HOME/.diary

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 1024

int main(void) {
    char path[MAX];
    // could use sprintf or strcat
    sprintf(path, "%s/.diary", getenv("HOME"));

    FILE *diary = fopen(path, "r");
    if (diary == NULL) {
        perror("$HOME/.diary");
        exit(1);
    }

    int c = getc(diary);
    while (c != EOF) {
        putc(c, stdout);
        c = getc(diary);
    }

    return 0;
}