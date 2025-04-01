#include <spawn.h>

int main(void) {
    pid_t pid;
    posix_spawn(pid, "/usr/bin/date", NULL, NULL, "+%d-%m-%Y", NULL);
}