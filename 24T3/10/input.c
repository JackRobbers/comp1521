#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int result = 0;

void *timer() {
    int i = 0;
    while (i < 10) {
        // sleep for a second
        sleep(1);
        printf("I'm awake\n");
        i++;
    }
    result = 1;
}

int main(void) {
    pthread_t thread;
    pthread_create(&thread, NULL, timer, NULL);

    // int num;    
    // while (1) {
    //     printf("enter a number: \n");
    //     scanf("%d", &num);

    //     printf("num * num = %d and result is %d\n", num * num, result);
    // }
    printf("%d\n", result);
    pthread_join(thread, NULL);
    printf("%d\n", result);
}