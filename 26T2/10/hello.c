#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int i = 10;


// do processing
void *hello(void *) {
    while (1) {
        printf("i is: %d\n", i);
        i++;
        sleep(1);
    }
}

// take input
int main(void) {
    pthread_t thread;
    pthread_create(&thread, NULL, &hello, NULL);

    // block / wait for thread to finish
    
    while (scanf("%d", &i) == 1) {
        
    }

    pthread_join(thread, NULL);
}