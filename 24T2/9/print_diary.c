// read $HOME/.diary
// . means hidden file!

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 1024

int main(void) {
    // use getenv to find the value of an environment variable.
    char *home = getenv("HOME");
    
    // sprintf - insecure. buffer overflow attacks
    char path[MAX];
    // could have also used strcat
    snprintf(path, MAX, "%s/.diary", home);

    FILE *diary = fopen(path, "r");    
    if (diary == NULL) {
        perror("$HOME/.diary");
        exit(1);
    }

    // print it out
    // fprintf version
    // could also do fgetc, fputc or fgets fputs 

    char line[MAX];
    while (fgets(line, MAX, diary) != NULL) {
        // equivalent to printf("%s", line);
        fprintf(stdout, "%s", line);
    }

    return 0;
}