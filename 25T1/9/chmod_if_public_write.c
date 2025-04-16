#include <sys/stat.h>
#include <stdio.h>

void chmod_if_needed(char *filename);

// take filenames as command line arguments
int main(int argc , char *argv[]) {
    for (int i = 1; i < argc; i++) {
        chmod_if_needed(argv[i]);
    }
    
    return 0;
}

void chmod_if_needed(char *filename) {
    // see if a file is publically writeable
    struct stat s;
    if (stat(filename, &s) == -1) {
        perror(filename);
        return;
    } 

    // permissions are the last 9 bits of st_mode;

    // check for publically writeable
    if (s.st_mode & S_IWOTH) {
        // if so, make it no longer public write, whilst preserving existing permissions
        s.st_mode = s.st_mode & ~S_IWOTH;

        chmod(filename, s.st_mode);
    }


    
}