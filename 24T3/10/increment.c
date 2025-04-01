x#include <stdio.h>
#include <pthread.h>

int global_total = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *add_5000_to_counter(void *data) {
    for (int i = 0; i < 5000; i++) {
        // sleep for 1 nanosecond, needed to force this to take time
        nanosleep (&(struct timespec){.tv_nsec = 1}, NULL);

        pthread_mutex_lock(&mutex);
        global_total++;
        pthread_mutex_unlock(&mutex);
        // lw $t0, global_total 
        // addi $t0, $t0, 1
        // sw $t0, global_total
    }

    return NULL;
}

int main(void) {
    pthread_t thread1;
    pthread_create(&thread1, NULL, add_5000_to_counter, NULL);

    pthread_t thread2;
    pthread_create(&thread2, NULL, add_5000_to_counter, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // if program works correctly, should print 10000
    printf("Final total: %d\n", global_total);
}