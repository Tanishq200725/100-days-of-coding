/*Write a program to take an input array of size n. The array should contain all the integers between 0 to n except for one. Print that missing number
*/
#include <stdio.h>
int main() {
    int n, i, sum = 0, total_sum;
    printf("Enter the size of the array (n): ");
    scanf("%d", &n);
    int arr[n - 1];
    printf("Enter %d integers between 0 to %d (one number will be missing):\n", n - 1, n);
    for (i = 0; i < n - 1; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    total_sum=n*(n+1)/2;
    printf("The missing number is: %d\n", total_sum - sum);
    return 0;
}