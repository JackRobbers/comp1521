// print out $HOME/.diary

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

int main(void) {
    char *home = getenv("HOME"); // gives /home/jack
  
    int length = strlen(home) + 8; // 7 chars for diary, 1 for null terminator
    char *path = malloc(sizeof(char) * length);
    snprintf(path, length, "%s/.diary", home); // could also use strncat
    
    FILE *file = fopen(path, "r");

    if (file == NULL) {
        perror("couldn't open file:");
        exit(1);
    }

    char line[MAX];
    while (fgets(line, MAX, file) != NULL) {
        fputs(line, stdout);
    }
}