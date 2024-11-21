#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int weight;
    int profit;
    double ratio;
} Item;
int compare(const void *a, const void *b) {
    Item *item1 = (Item *)a;
    Item *item2 = (Item *)b;
    if (item1->ratio > item2->ratio) return -1;
    else if (item1->ratio < item2->ratio) return 1;
    return 0;
}
void fractionalKnapsack(Item items[], int n, int capacity) {
    qsort(items, n, sizeof(Item), compare);
    double totalProfit = 0.0;
    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            totalProfit += items[i].profit;
            capacity -= items[i].weight;
        } else {
            totalProfit += items[i].profit * ((double)capacity / items[i].weight);
            break;
        }
    }
    printf("Maximum Profit: %.2f\n", totalProfit);
}
int main() {
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    Item items[n];
    printf("Enter weight and profit for each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d - Weight: ", i + 1);
        scanf("%d", &items[i].weight);
        printf("Item %d - Profit: ", i + 1);
        scanf("%d", &items[i].profit);
        items[i].ratio = (double)items[i].profit / items[i].weight;
    }
    fractionalKnapsack(items, n, capacity);
    return 0;
}
