// print the size of the file
// print the permissions as a string

#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    struct stat s;
    if (stat(argv[1], &s) == -1) {
        perror(argv[1]);
        return 1;
    };

    printf("Size: %ld\n", s.st_size);
    char *full_permission = "rwxrwxrwx";

    if (s.st_mode & S_IFDIR) {
        printf("d");
    } else {
        printf("-");
    }

    for (int i = 8; i >= 0; i--) {
        // permissions are the last 9 bits
        // rwxr-xr--
        //       ^
        // 00rwxr-xr
        // 00000000r
        if (s.st_mode >> i & 1) {
            printf("%c", full_permission[8 - i]);

        } else {
            printf("-");
        }
    }
    printf("\n");
}