#include <spawn.h>
#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>

void spawn_and_wait(char *argv[]) {
    printf("The output is: ");
    fflush(stdout);

    pid_t pid;
    int error = posix_spawn(&pid, argv[0], NULL, NULL, argv, NULL);
    if (error != 0) {
        errno = error;
        perror("spawn");
    }

    waitpid(pid, NULL, 0);
}

int main(void) {
    char *date_argv[] = {"/usr/bin/date", "+%d-%m-%Y", NULL};
    spawn_and_wait(date_argv);

    char *date2_argv[] = {"/usr/bin/date", "+%T", NULL};
    spawn_and_wait(date2_argv);

    return 0;
}