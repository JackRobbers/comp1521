#include <stdio.h>
#include <unistd.h>
#include <spawn.h>
#include <sys/wait.h>
    
void spawn(char *command[]) {
    pid_t pid;
    if (posix_spawn(&pid, command[0], NULL, NULL, command, NULL) != 0) {
        perror(command[0]);
    }

    printf("%d\n", pid);

    waitpid(pid, NULL, 0);
}

int main(void) {
    printf("%d\n", getpid());

    char *sleep[] = {"/usr/bin/sleep", "1", NULL};
    spawn(sleep);

    char *date[] = {"/usr/bin/date", "+%d-%m-%Y", NULL};
    spawn(date);
    char *time[] = {"/usr/bin/date", "+%T", NULL};
    spawn(time);



}