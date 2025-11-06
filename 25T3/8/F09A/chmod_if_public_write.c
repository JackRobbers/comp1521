// check if agrv[1] ,argv[2], ... are public write
// and change it if so

#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("not enough args");
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        struct stat info;
        stat(argv[i], &info);

        if (info.st_mode & S_IWOTH) {
            printf("%s was publically writeable, fixing\n", argv[i]);

            chmod(argv[i], info.st_mode & ~S_IWOTH);
        } else {
            printf("%s wasn't publically writeable\n", argv[i]);
        }
    }

}
