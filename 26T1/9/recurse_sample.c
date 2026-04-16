// look at the files in the current directory and it's children
// pathname

#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX 1024

void walk(char *current) {
    // list dir
    printf("Walking %s\n", current);
    
    DIR *directory = opendir(current);
    struct dirent *current_file;

    while ((current_file = readdir(directory)) != NULL) {
        // could use DT_DIR but didn't seem to work
        // do stat instead

        char new[MAX];
        sprintf(new, "%s/%s", current, current_file->d_name);
        struct stat s;
        stat(new, &s);

        if (strcmp(current_file->d_name, "..") != 0 &&
            strcmp(current_file->d_name, ".") != 0) {
            printf("%s\n", current_file->d_name);
            if (S_ISDIR(s.st_mode)) {
                walk(new);
            }
        }
    }

    // recurse
}

int main(void) {
    // get cwd
    char current[MAX];
    getcwd(current, MAX);

    walk(current);
}
