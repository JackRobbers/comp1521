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
    // get info about the file with stat
    struct stat s;
    int error = stat(pathname, &s);
    if (error == -1) {
        perror(pathname);
        exit(1);
    }

    // see if a file is publically writeable
    if (s.st_mode & S_IWOTH) {
        // if it is, make is no longer publically writable

        chmod(pathname, s.st_mode ^ S_IWOTH);
        // or chmod(pathname, s.st_mode & ~S_IWOTH);
        printf("%s is no longer publically writeable\n", pathname);
    } else {
        printf("%s is not publically writeable\n", pathname);
    }

}