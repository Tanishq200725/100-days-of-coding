//'Insert an element in a sorted array at the appropriate position.

#include<stdio.h>
int main(){
int i,n,x,pos=0;
printf("enter size of array:");
scanf("%d",&n);
int arr[n],arr1[n+1];
printf("enter sorted elements:");
for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
}
 printf("Enter element to insert: ");
    scanf("%d", &x);
    if(pos < n && arr[pos] < x) {
        pos++;
    }
    for (i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = x;
    n++;  
    printf("Array after insertion: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

return 0;
}
