#include <stdio.h>
#include <sys/stat.h>

// argv[] is a list of filenames
int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        struct stat s;
        if (stat(argv[i], &s) == -1) {
            perror(argv[i]);
            return 1;
        }
        // check, is the file excutable by anyone
        // if (s.st_mode & S_IXOTH) {
        //     printf("%s executable by anyone\n", argv[i]);
        // }

        // if (S_ISREG(s.st_mode)) {
        //     printf("%s is a regular files\n", argv[i]);
        // }

        // print a permission string
        if (S_ISDIR(s.st_mode)) {
            printf("d");
        } else if (S_ISREG(s.st_mode)) {
            printf("-");
        } else {
            printf("something weird\n");
        }

        char *perms = "rwx";
        for (int i = 0; i < 9; i++) {
            // last 9 bits are permissions
            if (s.st_mode >> (8 - i) & 1) {
                printf("%c", perms[i % 3]);
            } else {
                printf("-");
            }
        }

        printf(" %s\n", argv[i]);

        // publically writeable is bad
        // change it!
        if (s.st_mode & S_IWOTH) {
            printf("%s was pubically writeable, fixed\n", argv[i]);
            chmod(argv[1], s.st_mode & ~S_IWOTH);
        }
    }
}