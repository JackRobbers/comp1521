#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int counter;

void *thread_counter_update(void *args) {
    char *message = (char *) args;
    while (1) {
        counter += 10;
        printf("%s: %d\n", message, counter);
        sleep(1);
    }
    return (void *) 1;
}

int main(void) {
    pthread_t handle;
    pthread_create(&handle, NULL, thread_counter_update, "counter is");

    while (1) {
        scanf("%d", &counter);
    }

    void *return_value;
    pthread_join(handle, &return_value);
    int *return_int = (int *) return_value;
}

