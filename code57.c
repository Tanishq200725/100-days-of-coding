//Find the maximum and minimum element in an array.

#include<stdio.h>
int main(){
int i,n,max,min;
printf("enter no elements of array:");
scanf("%d",&n);
int arr[n];
printf("enter elements of array:");
for(i=0;i<n;i++){
    scanf("%d",&arr[n]);
}
max=arr[0];
min=arr[0];

for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    printf("%d is max",max);
    printf("%d id min",min);
    return 0;
}



