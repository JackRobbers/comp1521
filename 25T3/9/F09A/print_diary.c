// opens $HOME/.diary
// prints out the contents

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1024

int main(void) {
    char *home = getenv("HOME");

    char *path = strncat(home, "/.diary", strlen(home) + strlen("/.diary") + 1);
    
    // char *secret_password = "secret_password";
    strcat(home, "/diary");
    
    FILE *file = fopen(path, "r+");
    if (file == NULL) {
        perror("");
        return 1;
    }
    
    char line[MAX];

    while (fgets(line, MAX, file) != NULL) {
        fputs(line, stdout);
    }

    if (scanf() == secret_password) {
        open_bank_vault()
    }
 }