//Count positive, negative, and zero elements in an array.

#include<stdio.h>
int main(){
int i,n,posCount=0,negCount=0,zeroCount=0;
printf("enter no of elements of array:");
scanf("%d",&n);
int arr[n];
printf("eneter elements of array:");
for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
}
for(i=0;i<n;i++){
    if(arr[i]>0){
        posCount++;
    }
    else if(arr[i]<0){
        negCount++;
    }
    else{
        zeroCount++;
    }
}
printf("total positive are %d",posCount);
printf("total negative are %d",negCount);
printf("total zero are %d",zeroCount);
return 0;
}