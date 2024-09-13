
#include <errno.h>
#include <spawn.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

extern char **environ;

void spawn(char *command[]);

int main(void) {
    char *command[] = {"/usr/bin/date", "+%T", NULL};
    spawn(command);
    char *command1[] = {"/usr/bin/date", "+%d-%m-%Y", NULL};
    spawn(command1);
    char *command2[] = {"/usr/bin/whoami", NULL};
    spawn(command2);
    
    return 0;
}

void spawn(char *command[]) {
    pid_t pid;
    int status = posix_spawn(&pid, command[0], NULL, NULL, command, environ);
    if (status != 0) {
        errno = status;
        perror("posix_spawn");
        exit(1);
    }

    int exit_status;
    // wait for the child process to finish.
    if (waitpid(pid, &exit_status, 0) == -1) {
        perror("waitpid");
        exit(1);
    } 
}