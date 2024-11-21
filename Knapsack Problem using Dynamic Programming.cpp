#include <stdio.h>
int max(int a, int b) {
    return (a > b) ? a : b;
}
void knapsack(int n, int weights[], int profits[], int capacity) {
    int dp[n + 1][capacity + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)
                dp[i][w] = max(profits[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    printf("Maximum Profit: %d\n", dp[n][capacity]);
}
int main() {
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    int weights[n], profits[n];
    printf("Enter weights and profits of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &weights[i], &profits[i]);
    }
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);
    knapsack(n, weights, profits, capacity);
    return 0;
}
