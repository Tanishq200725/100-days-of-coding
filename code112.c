/*Write a program to take an integer array arr as input. The task is to find the maximum sum of any contiguous subarray using Kadane's algorithm. Print the maximum sum as output. If all elements are negative, print the largest (least negative) element.*/
#include<stdio.h>
#include<limits.h>
int maxSubArraySum(int arr[], int size) {
    int max_so_far = INT_MIN;
    int max_ending_here = 0;

    for (int i = 0; i < size; i++) {
        max_ending_here += arr[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}
int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int max_sum = maxSubArraySum(arr, n);
    printf("Maximum contiguous subarray sum is: %d\n", max_sum);
    return 0;
}