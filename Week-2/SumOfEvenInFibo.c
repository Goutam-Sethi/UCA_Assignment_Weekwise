#include <stdio.h>

int SumOfEvenFiboBrute(int n) {
    int prev = 1, curr = 1;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        int next = prev + curr;
        prev = curr;
        curr = next;

        if (curr > n)
            break;

        if (curr % 2 == 0)
            sum += curr;
    }

    return sum;
}

int SumOfEvenFiboOptimized(int n) {
    int a = 2;
    int b = 8;
    int sum = 0;

    while (a <= n) {
        sum += a;

        int c = 4 * b + a;
        a = b;
        b = c;
    }

    return sum;
}

int main() {
    int n = 10;
    printf("Brute Force: %d\n", SumOfEvenFiboBrute(n));
    printf("Optimized : %d\n", SumOfEvenFiboOptimized(n));

    n = 50;
    printf("Brute Force: %d\n", SumOfEvenFiboBrute(n));
    printf("Optimized : %d\n", SumOfEvenFiboOptimized(n));

    return 0;
}