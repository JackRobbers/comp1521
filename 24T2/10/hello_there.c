#include <stdio.h>
#include <pthread.h>

// print  outs a message in a loop
void *print_message(void *data) {
    char *string = data;

    while (1) {
        printf("%s\n", string);
    }

}

int main(void) {
    pthread_t thread;
    pthread_create(&thread, NULL, print_message, "hello");

    // print out "there"
    while (1) {
        printf("there\n");
    }

    return 0;
}