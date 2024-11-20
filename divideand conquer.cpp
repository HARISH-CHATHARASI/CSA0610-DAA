#include <stdio.h>

void findMaxMin(int arr[], int left, int right, int* min, int* max) {
    if (left == right) {
        *min = *max = arr[left];
        return;
    }

    int mid = left + (right - left) / 2;
    int min1, max1, min2, max2;

    findMaxMin(arr, left, mid, &min1, &max1);
    findMaxMin(arr, mid + 1, right, &min2, &max2);

    *min = (min1 < min2) ? min1 : min2;
    *max = (max1 > max2) ? max1 : max2;
}

int main() {
    int arr[] = {2, 8, 3, 1, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int min, max;
    findMaxMin(arr, 0, size - 1, &min, &max);
    printf("Minimum: %d\nMaximum: %d\n", min, max);
    return 0;
}
