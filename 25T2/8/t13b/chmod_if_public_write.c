// check if file is public write, turn it off if so

#include <sys/stat.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        struct stat s;
        stat(argv[i], &s);

        // s.st_mode is the permissions
        if (s.st_mode & S_IWOTH) {
            chmod(argv[i], s.st_mode & ~S_IWOTH);
        } else {
            printf("%s not publically writeable\n", argv[i]);
        }
    }
}