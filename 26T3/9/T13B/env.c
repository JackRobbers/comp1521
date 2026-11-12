
#include <stdio.h>
#include <stdlib.h>
int main(void) {
    char *env = getenv("COMP1521");
    printf("%s\n", env);
    return 0;
}