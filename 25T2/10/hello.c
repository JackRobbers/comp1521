#include <stdio.h>
#include <pthread.h>

void *thread_hello(void *arg) {
    // while (1) {
    int *limit = arg;
    for (int i = 0; i < *limit; i++) {
        printf("%d %d\n", i, *limit);
    }
    // }
}

int main(void) {
    pthread_t thread[5];
    int limits[5] = {2, 5, 10, 2, 5};

    for (int i = 0; i < 5; i++) {
        pthread_create(&thread[i], NULL, &thread_hello, &limits[i]);

    }

    for (int i = 0; i < 5; i++) {
        pthread_join(thread[i], NULL);
    }
    return 0;
}