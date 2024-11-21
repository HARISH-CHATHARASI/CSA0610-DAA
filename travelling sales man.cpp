#include <stdio.h>
#include <limits.h>
#define MAX 20
#define INF INT_MAX
int min(int a, int b) {
    return (a < b) ? a : b;
}
int tsp(int graph[MAX][MAX], int n) {
    int dp[1 << n][n];
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = INF;
        }
    }
    dp[1][0] = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int u = 0; u < n; u++) {
            if (mask & (1 << u)) { 
                for (int v = 0; v < n; v++) {
                    if ((mask & (1 << v)) && u != v && graph[v][u] != 0) {
                        dp[mask][u] = min(dp[mask][u],
                                          dp[mask ^ (1 << u)][v] + graph[v][u]);
                    }
                }
            }
        }
    }
    int result = INF;
    for (int i = 1; i < n; i++) {
        if (graph[i][0] != 0) {
            result = min(result, dp[(1 << n) - 1][i] + graph[i][0]);
        }
    }
    return result;
}
int main() {
    int n, graph[MAX][MAX];
    printf("Enter the number of cities: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix (use 0 for no path):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    int cost = tsp(graph, n);
    if (cost < INF) {
        printf("The minimum cost of the tour is: %d\n", cost);
    } else {
        printf("No solution exists.\n");
    }
    return 0;
}
