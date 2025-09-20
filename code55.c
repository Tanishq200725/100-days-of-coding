//Read and print elements of a one-dimensional array.
#include<stdio.h>
int main(){
int i,n;
printf("enter no elements of array:");
scanf("%d",&n);
int arr[n];
printf("enter elements of array:");
for(i=0;i<n;i++){
scanf("%d",&arr[i]);
}
for(i=0;i<n;i++){
    printf("%d\n",arr[i]);
}
return 0;

}