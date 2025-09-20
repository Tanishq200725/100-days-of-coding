//Count even and odd numbers in an array.
#include<stdio.h>
int main(){
int i,n,evenCount=0,oddCount=0;
printf("enter size of array:");
scanf("%d",&n);
int arr[n];
printf("enter elements of array:");
for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
}
for(i=0;i<n;i++){
    if(arr[i]%2==0){
        evenCount++;
    }
    else{
        oddCount++;
    }
}
printf("total even is %d",evenCount);
printf("total odd are %d",oddCount);
return 0;



}