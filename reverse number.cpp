#include <stdio.h>
int reverseNumber(int n, int reversed) {
    if (n == 0)
        return reversed;
    return reverseNumber(n / 10, reversed * 10 + n % 10);
}
int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Reversed Number: %d\n", reverseNumber(n, 0));
    return 0;
}
