// if a file is publically writable, change it's permission to not be
// otherwise, say it's already safe!

#include <sys/stat.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        struct stat stats;
        stat(argv[i], &stats);
        printf("%o\n", stats.st_mode);
        if (stats.st_mode & S_IWOTH) {
            printf("%s is publically writetable, fixing\n", argv[i]);
            chmod(argv[i], stats.st_mode ^ S_IWOTH); // made it no longer publically writeable

        }   else {
            printf("%s was not publically writeable\n", argv[i]);
        }
    }
}