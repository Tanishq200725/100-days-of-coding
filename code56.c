//Find the sum of array elements.

#include<stdio.h>
int main(){
int i,n,sum=0;
printf("enter number of elements in array:");
scanf("%d",&n);
int arr[n];
printf("enter elements of array:");
for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
}
for(i=0;i<n;i++){
    sum=sum+arr[i];

}
printf("%d is the final sum",sum);





return 0;


}