#include <spawn.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>

void spawn_process(char *argv[]) {
    pid_t pid;
    int error = posix_spawn(&pid, argv[0], NULL, NULL, argv, NULL);
    if (error != 0) {
        errno = error;
        perror("spawn");
        exit(EXIT_FAILURE);
    }

    waitpid(pid, NULL, 0);
}

int main(void) {
    char *date_argv[] = {"/usr/bin/date", "+%d-%m-%Y", NULL};
    spawn_process(date_argv);

    char *date2_argv[] = {"/usr/bin/date", "+%T", NULL};
    spawn_process(date2_argv);

    char *whoami_argv[] = {"/usr/bin/whoami", NULL};
    spawn_process(whoami_argv);

    

    return 0;
}