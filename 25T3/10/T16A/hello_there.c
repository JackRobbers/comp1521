#include <pthread.h>
#include <stdio.h>

void *there(void *data);

int main(void) {
    pthread_t thread_handle;
    pthread_create(&thread_handle, NULL, &there, NULL);

    // while () {
    printf("hello\n");
    // }

    pthread_join(thread_handle, NULL);

    return 0;
}

void *there(void *data) {
    // while () {
    printf("there\n");
    // }
}