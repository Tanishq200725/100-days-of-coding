/*Write a program to take an integer array arr and an integer k as inputs. The task is to find the first negative integer in each subarray of size k moving from left to right. If no negative exists in a window, print "0" for that window. Print the results separated by spaces as output.*/
#include <stdio.h>
void firstNegativeInWindow(int arr[],int n,int k) {
    for (int i=0;i<=n-k;i++) {
        int found = 0;
        for (int j = 0; j < k; j++) {
            if (arr[i + j] < 0) {
                printf("%d ", arr[i + j]);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("0 ");
        }
    }
    printf("\n");
}
int main() {
    int n, k;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the size of the subarray (k): ");
    scanf("%d", &k);
    firstNegativeInWindow(arr, n, k);
    return 0;
}
