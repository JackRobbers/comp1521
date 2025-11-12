// change perms if public write

#include <sys/stat.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    // for each file, get the permissions
    for (int i = 1; i < argc; i++) {
        struct stat s;
        stat(argv[i], &s);

        // check if it's public write
        if (s.st_mode & S_IWOTH) {
            // if so, change the permission.
            chmod(argv[i], s.st_mode & ~S_IWOTH);
            printf("Ahhhh! that was close, made %s not publically writeable\n", argv[i]);
        } else {
            printf("We're safe! file %s wasn't public write\n", argv[i]);
        }
    }



    return 0;
}