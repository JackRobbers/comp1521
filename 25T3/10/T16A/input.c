#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

int counter = 0;

void *thread_calculation(void *);

int main(void) {
    pthread_t thread_handle;
    pthread_create(&thread_handle, NULL, &thread_calculation, NULL);


    // main thread takes inputs
    while (1) {
        scanf("%d", &counter);
    }
}

void *thread_calculation(void *args) {
    // child thread does calculation
    while (1) {
        counter += 10;
        printf("counter: %d\n", counter);
        sleep(1);
    }
}