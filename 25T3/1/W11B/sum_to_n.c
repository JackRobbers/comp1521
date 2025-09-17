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
int sum(int n) {
    int result = 0;
    for (int i = 0; i <= n; i++) {
        result += i;
    }
    return result;
}

// recursive version
int sum_recursive(int n) {
    if (n == 0) {
        // base case
        return 0;
    } else {
        // recursive case
        return n + sum_recursive(n - 1);
    }
}

// sum(4)
// 4 + sum(3)
// 4 + 3 + sum(2)
// 4 + 3 + 2 + sum(1)
// 4 + 3 + 2 + 1 + sum(0)
// 4 + 3 + 2 + 1 + 0
