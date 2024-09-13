#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *feed_me(void *data) {
    while (1) {
        printf("feed me input\n");
        sleep(1);
    }
}

int main(void) {
    pthread_t thread;
    pthread_create(&thread, NULL, feed_me, NULL);

    char line[1024];
    while (fgets(line, 1024, stdin) != NULL) {
        printf("you entered: %s", line);
    }

    // not 100% needed here, but can be useful elsewhere
    pthread_cancel(thread);
    return 0;
}