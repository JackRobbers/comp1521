#include <stdio.h>
#include <pthread.h>
#include <stdatomic.h>

atomic_int global_total = 0;
// pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *add_5000_to_counter(void *data) {
    int i;
    for (i = 0; i < 5000; i++) {
        // sleep for 1 nanosecond
        nanosleep (&(struct timespec){.tv_nsec = 1}, NULL);
        
        // increment the global total by 1
        // pthread_mutex_lock(&lock);
        global_total++;
        // pthread_mutex_unlock(&lock);
    }
    printf("finish the loop! %d\n", i);

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

    return 0;
}