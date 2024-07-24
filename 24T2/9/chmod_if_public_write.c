#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void chmod_if_needed(char *pathname);

int main(int argc, char *argv[]) {
    // loop through filenames in argv[]
    for (int i = 1; i < argc; i++) {
        chmod_if_needed(argv[i]);
    }
    return 0;
}

void chmod_if_needed(char *pathname) {
    // getting struct stat for the file
    struct stat s;
    int error = stat(pathname, &s);
    if (error == -1) {
        perror(pathname);
        exit(1);
    }

    // see if the file is publically writeable
    // printf("%o %d\n", s.st_mode, s.st_mode & S_IWOTH); // 2 -> 0010

    // if it is, make it not publically writeable
    if (s.st_mode & S_IWOTH) {
        printf("%s is no longer publically writeable\n", pathname);
        chmod(pathname, s.st_mode ^ S_IWOTH);
        // or could do:
        // chmod(pathname, s.st_mode & ~S_IWOTH);
    } else {
        printf("%s was not publically writeable\n", pathname);
    }
}