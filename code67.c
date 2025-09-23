//Insert an element in an array at a given position.
#include<stdio.h>
int main(){
int i,n,pos=0,x;
printf("enetr size of array:\n");
scanf("%d",&n);
int arr[n],arr1[n+1];
printf("enter sorted elements:");
for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
}
printf("enter elemnts to insert:");
scanf("%d",&x);
printf("Enter position to insert (0 to %d): ", n);
    scanf("%d", &pos);

    if (pos < 0 || pos > n) {
        printf("Invalid position!\n");
        return 1;
    }
    for (i = 0; i < pos; i++) {
        arr1[i] = arr[i];
    }
    arr1[pos] = x;
    for (i = pos; i < n; i++) {
        arr1[i + 1] = arr[i];
    }

    printf("Array after insertion: ");
    for (i = 0; i < n + 1; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");







}