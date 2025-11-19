#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int counter = 0;

void *add(void *) {
    while (1) {
        counter += 10;
        printf("%d\n", counter);
        sleep(1);
    } 
}

int main(void) {
    pthread_t th;
    pthread_create(&th, NULL, add, NULL);


    while (1) {
        scanf("%d", &counter);
    }

}

