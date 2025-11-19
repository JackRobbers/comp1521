// use posix_spawn to run other processes

#include <spawn.h>
#include <stdio.h>
#include <errno.h>
#include <sys/wait.h>

int main(void) {

    pid_t pid;
    char *now_argv[] = {"/usr/bin/date", "+%d-%m-%Y", NULL};
    int error = posix_spawn(&pid, "/usr/bin/date", NULL, NULL, now_argv, NULL);
    if (error != 0) {
        errno = error;
        perror("spawn");
    }

    waitpid(pid, NULL, 0);

    printf("Hello\n");

    

    return 0;
}