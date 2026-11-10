#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

void print_some_file_info(char *filename);

int main(int argc, char *argv[]) {
    // Loop over command line arguments
    for (int arg = 1; arg < argc; arg++) {
        print_some_file_info(argv[arg]);
    }
}

void print_some_file_info(char *filename) {
    // Use stat to get file information
    struct stat s;

    // check that stat worked
    if (stat(filename, &s) != 0) {
        perror(filename);
        return;
    }

    // get the mode (permissions) of the file
    mode_t mode = s.st_mode;

    // check if the file is a directory
    if ((mode & S_IFDIR) == S_IFDIR) {
        printf("The directory '%s' has mode 0x%x == 0%o\n", filename, mode, mode);

        // check if the file is a regular file
    } else if (S_ISREG(mode)) {
        printf("The file '%s' has mode 0x%x == 0%o\n", filename, mode, mode);
    }

    // check if the file is publically readable
    if (mode & S_IROTH) {
        printf("%s is publically readable\n", filename);
    }

    // can the owner read?
    if (mode & S_IRUSR) {
        printf("%s is readable by the owner\n", filename);
    }

    // publically writeable
    if (mode & S_IWOTH) {
        printf("woah %s was publically writeable, fixing that\n", filename);
        chmod(filename, mode & ~S_IWOTH);
    }
}