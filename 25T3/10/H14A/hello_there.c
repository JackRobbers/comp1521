#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *thread_hello(void *) {
    // while (1) {
    printf("hello\n");
    // }
}

int main(void) {
    pthread_t thread_handle;
    pthread_create(&thread_handle, NULL, thread_hello, NULL);

    // while (1) {
    printf("there\n");
    pthread_join(thread_handle, NULL);
    // sleep(1);
    // }

    return 0;
}

