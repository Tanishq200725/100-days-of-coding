//Search for an element in an array using linear search.
#include<stdio.h>
int main(){
int i,n,j,count=0;
printf("enetr no of elements of array:");
scanf("%d",&n);
int arr[n];
printf("enter elements of array:");
for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
}
printf("enter the no to be searched:");
scanf("%d",&j);
for(i=0;i<n;i++){
    if(arr[i]==j){
        printf("%d the no is found",j);
        count++;
        break ;
    }
}
for(i=0;i<n;i++){
if(arr[i]!=j){
    printf("the no is not found");
}
}
return 0;



}