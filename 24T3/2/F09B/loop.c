// Print every third number from 24 to 42.
#include <stdio.h>

int main(void) {
    // This 'for' loop is effectively equivalent to a while loop.
    // i.e. it is a while loop with a counter built in.

    int x = 24; 

loop_condition:
    if (x >= 42) goto epilogue;

loop_body:
        printf("%d\n", x);
        x += 3;
        goto loop_condition;

epilogue:
    return 0;
}