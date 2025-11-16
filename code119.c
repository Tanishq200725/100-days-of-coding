/*Write a program to take an integer array as input. Only one element will be repeated. Print the repeated element. Try to find the result in one single iteration.*/
#include <stdio.h>
int main() {
    int n, i, repeatedElement;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array (one element will be repeated):\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int seen[100000] = {0};
    for(i = 0; i < n; i++) {
        if(seen[arr[i]] == 1) {
            repeatedElement = arr[i];
            break;
        }
        seen[arr[i]] = 1;
    }
    printf("The repeated element is: %d\n", repeatedElement);
    return 0;
}