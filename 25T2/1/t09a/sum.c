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

int sum(int n) {
    if (n == 1) {
        // base case
        return 1;
    } else {
        // recursive case
        return n + sum(n - 1);
    }
}

int sum(int n) {
    int result = 0;
    for (int i = 0; i <= n; i++) {
        result += i;
    }
    return result;
}

// sum(3)
// 3 + sum(2)
// 3 + 2 + sum(1)
// 3 + 2 + 1