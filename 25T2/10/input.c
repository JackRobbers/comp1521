// want 1 thread for input
// want 1 for calculation

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 1024

int counter = 0;

void *thread_countup(void *) {
    while (1) {
        counter++;
        sleep(1);
        printf("counter: %d\n", counter);
    }
}

int main(void) {
    pthread_t thread;
    pthread_create(&thread, NULL, &thread_countup, NULL);

    char line[MAX];
    while (fgets(line, MAX, stdin) != NULL) {
        counter = atoi(line);
    }
}