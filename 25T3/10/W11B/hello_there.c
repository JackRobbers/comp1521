#include <stdio.h>
#include <pthread.h>
#include <unistd.h>


void *there_thread(void *);

int main(void) {
    pthread_t thread_handle;
    pthread_create(&thread_handle, NULL, there_thread, NULL);

    // while (1) {
    sleep(1);
    printf("hello\n");


    // }
    pthread_join(thread_handle, NULL);

    return 0;
}

void *there_thread(void *) {
    // while (1) {
    printf("there\n");
    // }
}