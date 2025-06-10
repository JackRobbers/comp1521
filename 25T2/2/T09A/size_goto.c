#include <stdio.h>

int main(void) {
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);

    if (x > 100 && x < 1000) goto medium;
    goto small_big;

medium:
    printf("medium\n");
    goto end;

small_big:
    printf("small/big\n");

end:
    return 0;
}