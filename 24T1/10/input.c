#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX 1024

int counter;

void *thread_run(void *data) {
    while (1) {
        printf("counter is %d\n", counter);
        sleep(1);
    }

    return NULL;
}

int main(void) {
    pthread_t thread;
    pthread_create(
        &thread,    // the pthread_t handle that will represent this thread
        NULL,       // thread-attributes -- we usually just leave this NULL
        thread_run, // the function that the thread should start executing
        NULL        // data we want to pass to the thread -- this will be
                    // given in the `void *data` argument above
    );

    char line[MAX];
    while (fgets(line, MAX, stdin) != NULL) {
        int i = atoi(line);
        counter += i;
        printf("add %d to counter\n", i);
    }

    return 0;
}