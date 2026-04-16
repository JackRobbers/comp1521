// given a file path as a command line argument and prints the file size (in bytes) and the file permissions as a string in a format similar to ls -l (e.g. -rw-r--r--)

// also check if public write, and remove it if so

#include <stdio.h>
#include <sys/stat.h>

int print_permissions(struct stat s) {
    // print the permissions string
    if (S_ISDIR(s.st_mode)) {
        printf("d");
    } else if (S_ISREG(s.st_mode)) {
        printf("-");
    } else {
        fprintf(stderr, "unimplemented file type");
        return -1;
    }

    char letters[4] = "rwx";

    for (int i = 0; i < 9; i++) {
        if (s.st_mode & (S_IRUSR >> i)) {
            printf("%c", letters[i % 3]);
        } else {
            printf("-");
        }
    }    
    printf("\n");
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "incorrect number of arguments\n");
        return 1;
    }

    struct stat s;
    if (stat(argv[1], &s) == -1) {
        perror(argv[1]);
        return 1;
    }

    // print the filesize
    printf("size: %ld\n", s.st_size);

    print_permissions(s);

    // is it publicly writeable
    if (s.st_mode & S_IWOTH) {
        printf("%s was publicly writeable, changing!\n", argv[1]);
        chmod(argv[1], s.st_mode  & ~S_IWOTH);

        // check the updated permissions
        if (stat(argv[1], &s) == -1) {
            perror(argv[1]);
            return 1;
        }
        print_permissions(s);
    } else {
        printf("Not public writeable, you're safe\n");
    }
 
    // change it if so
}