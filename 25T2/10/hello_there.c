#include <stdio.h>
#include <pthread.h>

void *hello_thread(void *) {
    for (int i = 0; i < 10; i++) {
        printf("%d\n", i);
    }
}

int main(void) {
    pthread_t threads[5];
    int a = 10;
    for (int i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, &hello_thread, &a);
    }
    
    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }
    

    return 0;
}
