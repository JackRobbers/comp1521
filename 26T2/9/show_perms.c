#include <sys/stat.h>
#include <stdio.h>

char *perm_chars = "rwx";


void print_perms(char *path) {
        struct stat s;

        stat(path, &s);

        printf("size: %ld\n", s.st_size);

        if (S_ISDIR(s.st_mode)) {
                printf("d");
        } else {
                printf("-");
        }
        // s.st_mode is the permissions
        for (int i = 0; i < 9; i++) {
                if (s.st_mode >> (8 - i) & 1) {
                        printf("%c", perm_chars[i % 3]);
                } else {
                        printf("-");
                }
        }

        printf("\n");


}

int main(int argc, char *argv[]) {

        print_perms(argv[1]);

        // check for public write, and modify if so
        struct stat s;
        stat(argv[1], &s);

        if (s.st_mode & S_IWOTH) {
                printf("woah, file is publically writeable fixing\n new perms: ");

                chmod(argv[1], s.st_mode ^ S_IWOTH);
                // equiv
                // chmod(argv[1], s.st_mode & ~S_IWOTH);
                
                print_perms(argv[1]);
        }


}