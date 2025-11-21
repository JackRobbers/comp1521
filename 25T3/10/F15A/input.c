#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int counter;

void *add_counter(void *) {
    while (1) {
        counter += 1;
        printf("%d\n", counter);
        sleep(1);
    }
}

int main(void) {
    pthread_t th;
    pthread_create(&th, NULL, add_counter, NULL);
    while (1) {
        scanf("%d", &counter);
    }

    return 0;
}