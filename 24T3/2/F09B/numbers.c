#include <stdio.h>

// rewrite using if (condition) goto label
// and add labels to our code
// no composite comparision (no && or ||)

int main(void) {
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);

    if (x <= 100) goto notmedium;
    if (x >= 1000) goto notmedium;
    printf("medium\n");
    goto epilogue;

notmedium: 
    printf("small/big\n"); \

epilogue:
    return 0;
}