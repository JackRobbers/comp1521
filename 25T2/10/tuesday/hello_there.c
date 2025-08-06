#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

struct thread_payload {
    int number;
    int limit;
};

void *hello_thread(void *arg) {
    struct thread_payload *payload = arg;
    for (int i = 0; i < payload->limit; i++) {
        printf("thread #%d %d\n", payload->number, i);
    }
}

int main(void) {
    pthread_t threads[5];
    for (int i = 0; i < 5; i++) {
        struct thread_payload *payload = malloc(sizeof(struct thread_payload));
        payload->number = i;
        payload->limit = 10; 
        pthread_create(&threads[i], NULL, &hello_thread, payload);
    }
    
    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
        // free()
    }
    

    return 0;
}
