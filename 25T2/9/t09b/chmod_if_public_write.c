// Given a list of files, make them no longer publically writeable if needed

#include <sys/stat.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        struct stat s;
        stat(argv[i], &s);

        // permissions are in s.st_mode

        // check for publically writeable
        if (s.st_mode & S_IWOTH) {
            chmod(argv[i], s.st_mode & ~S_IWOTH);
            printf("aaaaah, fixing that now\n");
        } else {
            printf("We're safe, file wasn't publically writeable\n");
        }
    }

    return 0;
}