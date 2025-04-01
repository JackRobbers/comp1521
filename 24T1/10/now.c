#include <stdio.h>
#include <spawn.h>
#include <stdlib.h>
#include <sys/wait.h>

extern char **environ;

void spawn(char *command[]);

int main(void) {
    char *command2[] = {"/bin/date", "+%d-%m-%y", NULL}; 
    spawn(command2);
    // char *command[] = {"./now", "+%T", NULL}; 
    // spawn(command);
    // char *command1[] = {"/bin/sleep", "5", NULL}; 
    // spawn(command1);
    return 0;
}

void spawn(char *command[]) {
    pid_t pid;
    if(posix_spawn(&pid, command[0], NULL, NULL, command, environ) != 0) {
        perror(command[0]);
        exit(1);
    }
    

    int return_status = 0;
    waitpid(pid, &return_status, 0);
    printf("%s return with status %d\n", command[0], return_status);
}