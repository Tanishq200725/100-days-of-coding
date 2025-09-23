//Delete an element from an array.
#include<stdio.h>
int main(){
int i,n,x,pos=0;
printf("enter size of array:");
scanf("%d",&n);
int arr[n],arr1[n-1];
printf("enter elemnts of array:");
for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
}
printf("enter element to be deleted:");
scanf("%d",&x);
printf("Enter position to delete (0 to %d): ", n - 1);
    scanf("%d", &pos);

    if (pos < 0 || pos >= n) {
        printf("Invalid position!\n");
        return 1;
    }
    for (i = 0; i < pos; i++) {
        arr1[i] = arr[i];
    }
    for (i = pos; i < n - 1; i++) {
        arr1[i] = arr[i + 1];
    }

    printf("Array after deletion: ");
    for (i = 0; i < n - 1; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");








}