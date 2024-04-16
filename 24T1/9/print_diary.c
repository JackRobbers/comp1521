// print contents of $HOME/.diary to stdout

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 1024

int main(void) {
    // open "$HOME/.diary"
    char *home_path = getenv("HOME");

    // snprintf
    char diary_path[MAX];
    snprintf(diary_path, MAX, "%s/.diary", home_path);

    // strcat version
    // diary_path = strcat(home_path, "/.diary")
    
    FILE *diary = fopen(diary_path, "r");
    if (diary != NULL) {
        char line[MAX];
        while(fgets(line, MAX, diary) != NULL) {
            printf("%s", line);
        }
    } else {
        perror(diary_path);
    }
}