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
    // run stat on the file
    struct stat s;
    stat(pathname, &s);
    // check it's permissions
    if (s.st_mode & S_IWOTH) {
    // if it is publically writable, make it not publically writeable
        printf("oops! %s is writeable by anyone! fixing that\n", pathname);
        chmod(pathname, s.st_mode & ~S_IWOTH);
    } else {
    // otherwise say the file is not publically writeable
        printf("%s is not publically writeable\n", pathname);
    }

}