//Reverse an array without taking extra space.

#include<stdio.h>
int main(){
int i,n,j;
printf("enter size of array:");
scanf("%d",&n);
int array[n];
printf("enter elements of array:");
for(i=0;i<n;i++){
    scanf("%d",&array[i]);
}
for(i=n-1;i>=0;i--){
    printf("%d",array[i]);
}
return 0;


}