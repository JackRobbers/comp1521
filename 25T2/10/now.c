#include <spawn.h>
#include <sys/wait.h>
#include <stdio.h>

int run_command_and_wait(char *command[]) {
    pid_t pid;
    // start a new process
    if (posix_spawn(&pid, command[0], NULL, NULL, command, NULL) != 0) {
        perror("spawn");
    };
    printf("%d\n", pid);

    // wait for process to finish, blocking
    waitpid(pid, NULL, 0);
}


int main(void) {
    char *date[] = {"/usr/bin/date", "+%d-%m-%Y", NULL};
    run_command_and_wait(date);
    
    char *whoami[] = {"/usr/bin/whoami", NULL};
    run_command_and_wait(whoami);

    char *pwd[] = {"/usr/bin/realpath", ".", NULL};
    run_command_and_wait(pwd);
}