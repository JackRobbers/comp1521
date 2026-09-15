#include <spawn.h>
#include <sys/wait.h>
extern char **environ;

int main(void) {
        int pid;

        char *date_argv[] = {"/usr/bin/date", "+%d-%m-%Y"};

        posix_spawn(&pid, date_argv[0], NULL, NULL, date_argv, environ);

        waitpid(pid, NULL, 0);

        char *date2_argv[] = {"/usr/bin/date", "+%T"};

        posix_spawn(&pid, date2_argv[0], NULL, NULL, date2_argv, environ);
}