#include <stdio.h>

int sum(int n);

int main(int argc, char *argv[]) {
        int n;
        printf("Enter a number: ");
        scanf("%d", &n);

        int result = sum(n);
        printf("Sum of all numbers up to %d = %d\n", n, result);

        return 0;
}

// // iterative version
// int sum(int n) {
//     int result = 0;
//     for (int i = 1; i <= n; i++) {
//         result += i;
//     }
//     return result;
// }

// recursive version

// sum(5) = 5 + 4 + 3 + 2 + 1
// sum(2) = 2 + 1
// sum(5) = 5 + 4 + 3 + sum(2)

// sum(5) = 5 + sum(4)
// sum(4) = 4 + sum(3)
// ...
// sum(1) = 1 + sum(0)
int sum(int n) {
    printf("I'm sum, called with n = %d\n", n);

    int return_val;
    if (n == 0) {
        return_val = 0;
    } else {
        return_val = n + sum(n - 1);
    }

    printf("returning from sum with n = %d\n", n);
    return return_val;
}