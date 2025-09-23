//Search in a sorted array using binary search.

#include<stdio.h>
int main(){
int i,n,y,count=0;
printf("enter size of arrray:");
scanf("%d",&n);
int arr[n];
printf("enter elements of array:");
for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
}
printf("enter the number to be searched:");
scanf("%d",&y);
    int low = 0, high = n - 1, mid;
    int found = -1;  // -1 means not found

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == y) {
            found = mid;
            break;
        } else if (arr[mid] < y) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
         if (found != -1)
        printf("%d found at index %d (position %d)\n", y, found, found + 1);
    else
        printf("%d is not in the array.\n", y);
return 0;

}

