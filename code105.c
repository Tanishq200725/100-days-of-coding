//Write a program to take an integer array nums of size n, and print the majority element. The majority element is the element that appears strictly more than ⌊n / 2⌋ times. Print -1 if no such element exists. Note: Majority Element is not necessarily the element that is present most number of times.
#include <stdio.h>
int main() {
    int nums[100], n;
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    int count = 0;
    int candidate = -1;
    for (int i = 0; i < n; i++) {
        if (count == 0) {
            candidate = nums[i];
        }
        if (nums[i] == candidate) {
            count++;
        } else {
            count--;
        }
    }
    count = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == candidate) {
            count++;
        }
    }
    if (count > n / 2) {
        printf("Majority element: %d\n", candidate);
    } else {
        printf("Majority element: -1\n");
    }

    return 0;
}