#include <spawn.h>
#include <sys/wait.h>
#include <stdio.h>

int main(void) {
    pid_t pid;
    char *args[] = {"/usr/bin/date", "+%d-%m-%Y", NULL};
    if (posix_spawn(&pid, "/usr/bin/date", NULL, NULL, args, NULL) != 0) {
        perror("spawn");
    };

    int return_status;
    waitpid(pid, &return_status, 0);
    printf("process %d return with status %d", pid, return_status);
}