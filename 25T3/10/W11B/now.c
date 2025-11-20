#include <spawn.h>
#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>

void spawn_and_wait(char *argv[]);

int main(void) {
    char *date[] = {"/usr/bin/date", "+%d-%m-%Y", NULL};
    spawn_and_wait(date);

    char *date2[] = {"/usr/bin/date", "+%T", NULL};
    spawn_and_wait(date2);

    char *whoami[] = {"/usr/bin/whoami", NULL};
    spawn_and_wait(whoami);

}

void spawn_and_wait(char *argv[]) {
    printf("The output is: ");
    fflush(stdout);

    pid_t pid;
    // returns error rather than setting errno.
    int error = posix_spawn(&pid, argv[0], NULL, NULL, argv, NULL);
    if (error != 0) {
        errno = error;
        perror(argv[0]);
    }

    waitpid(pid, NULL, 0);
}