#include <pthread.h>
#include <stdio.h>

void *thread_hello(void *args) {
    // while (1) {
    printf("hello\n");
    // }
}

int main(void) {
    pthread_t thread_handle;
    pthread_create(&thread_handle, NULL, thread_hello, NULL);

    // while (1) {
    printf("There\n");
    // }

    pthread_join(thread_handle, NULL);
}