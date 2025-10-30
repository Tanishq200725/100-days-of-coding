//Write a program to take an integer array arr and an integer k as inputs. Print the maximum sum of all the subarrays of size k.
#include <stdio.h>
int main(){
    int arr[100],n,k,i,j,max_sum=0,current_sum=0;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    printf("Enter the elements of the array: ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
}
    printf("Enter the size of the subarray k: ");
    scanf("%d",&k);
    for(i=0;i<k;i++){
        current_sum += arr[i];
    }
    max_sum = current_sum;
    for(i=k;i<n;i++){
        current_sum += arr[i] - arr[i-k];
        if(current_sum > max_sum){
            max_sum = current_sum;
        }
    }
    printf("The maximum sum of all subarrays of size %d is: %d\n", k, max_sum);
    return 0;
}