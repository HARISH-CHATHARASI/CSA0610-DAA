#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n, int divisor) {
    if (n < 2) return false;
    if (divisor == 1) return true;
    if (n % divisor == 0) return false;
    return isPrime(n, divisor - 1);
}

void printPrimes(int n, int current) {
    if (current > n) return;
    if (isPrime(current, current / 2)) printf("%d ", current);
    printPrimes(n, current + 1);
}

int main() {
    int n = 20; 
    printf("Prime numbers up to %d:\n", n);
    printPrimes(n, 2);
    printf("\n");
    return 0;
}
