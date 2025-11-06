// search for argv[1] in stdin or argv[2....]

#include <stdio.h>
#include <string.h>

#define MAX 1024

void search(FILE *file, char *search_term);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Not enough args\n");
        return 1;
    } else if (argc == 2) {
        search(stdin, argv[1]);
    } else { 
        for (int i = 2; i < argc; i++) {
            FILE *file = fopen(argv[i], "r");
            if (file == NULL) {
                perror(argv[i]);
            } else {
                search(file, argv[1]);
                fclose(file);   
            }
        }
    }

    return 0;
}


// look at each line in the file, see if search term is inside that line 
// print out the line number
void search(FILE *file, char *search_term) {
    char line[MAX];
    int i = 1;
    while (fgets(line, MAX, file) != NULL) {
        if (strstr(line, search_term) != NULL) {
            printf("line %d: %s", i, line);
        }
        i++;
    }
}