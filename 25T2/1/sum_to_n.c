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

// iterative version
// int sum(int n) {
//     int result = 0;
//     for (int i = 0; i <= n; i++) {
//         result += i;
//     }
//     return result;
// }

// recursive version
// for n. find n + (n - 1) + (n - 2) + ... (1)
int sum(int n) {
    if (n == 0) {
        // base case
        return 0;
    } else {
        // recursive case
        return n + sum(n - 1);
    }
}
