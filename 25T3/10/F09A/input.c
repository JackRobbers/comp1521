#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

int counter = 0;

void *add_counter(void *args) {
    char *message = (char *) args;
    int *runs = malloc(sizeof(int));
    *runs = 0;
    while (1) {
        printf("%s: %d, %d\n", message, counter, *runs);
        counter += 10;
        if (counter > 1000) {
            return runs;
        }
        (*runs)++;
        sleep(1);
    }
}

int main(void) {
    pthread_t handle;
    pthread_create(&handle, NULL, add_counter, "counter is");

    while (scanf("%d", &counter) == 1) {
        
    }  

    printf("finished\n");
    void *return_value;
    pthread_join(handle, &return_value);
    int *return_int = (int *) return_value;
    printf("took %d runs\n", *return_int);
}