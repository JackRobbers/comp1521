// ./command_line hello comp1521
// argc == 3
// argv l {"command_line", "hello", "comp1521"}

#include <stdio.h>
#include <stdlib.h>

// print the sum of the arguments
// atoi
int main(int argc, char *argv[]) {
        int total = 0;
        for (int i = 1; i < argc; i++) {
                total += atoi(argv[i]);
                // printf=("%s\n", argv[i]);
        }

        printf("Sum is: %d\n", total);
}