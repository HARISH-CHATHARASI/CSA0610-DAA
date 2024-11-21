#include <stdio.h>
#include <limits.h>

// Function to calculate the sum of frequencies from index i to j
int sum(int freq[], int i, int j) {
    int s = 0;
    for (int k = i; k <= j; k++) {
        s += freq[k];
    }
    return s;
}

// Function to compute the optimal cost of constructing a binary search tree
void optimalBST(int keys[], int freq[], int n) {
    int cost[n][n];

    // Initialize cost for single keys
    for (int i = 0; i < n; i++) {
        cost[i][i] = freq[i];
    }

    // Compute cost for trees of size 2 to n
    for (int L = 2; L <= n; L++) {
        for (int i = 0; i <= n - L; i++) { // Corrected condition
            int j = i + L - 1;
            cost[i][j] = INT_MAX;

            // Try every key as root in this range
            for (int r = i; r <= j; r++) {
                int c = ((r > i) ? cost[i][r - 1] : 0) +
                        ((r < j) ? cost[r + 1][j] : 0) +
                        sum(freq, i, j);

                if (c < cost[i][j]) {
                    cost[i][j] = c;
                }
            }
        }
    }

    printf("Optimal Cost: %d\n", cost[0][n - 1]);
}

int main() {
    int n;

    // Input number of keys
    printf("Enter the number of keys: ");
    scanf("%d", &n);

    int keys[n], freq[n];

    // Input keys and their frequencies
    printf("Enter keys and their frequencies (key frequency):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &keys[i], &freq[i]);
    }

    // Compute the optimal cost
    optimalBST(keys, freq, n);

    return 0;
}
