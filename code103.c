//Write a Program to take an array of integers as input, calculate the pivot index of this array. The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right. If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array. Print the leftmost pivot index. If no such index exists, print -1.
#include <stdio.h>
int main() {
    int arr[100], n;
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int totalSum = 0;
    for (int i = 0; i < n; i++) {
        totalSum += arr[i];
    }

    int leftSum = 0;
    int pivotIndex = -1;
    for (int i = 0; i < n; i++) {
        totalSum =totalSum-arr[i]; 
        if (leftSum == totalSum) {
            pivotIndex = i;
            break;
        }
        leftSum =leftSum+ arr[i];
    }

    printf("Pivot index: %d\n", pivotIndex);
    return 0;
}