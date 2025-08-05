#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

// one thread for input
// one thread for processing

#define MAX 1024

int counter = 0;

void *add_one(void *) {
    while (1) {
        counter += 1;
        sleep(1);
        printf("counter is %d\n", counter);
    }
}

int main(void) {
    pthread_t thread;
    pthread_create(&thread, NULL, &add_one, NULL);

    char line[MAX];
    while (fgets(line, MAX, stdin)) {
        counter = atoi(line);
    }
}