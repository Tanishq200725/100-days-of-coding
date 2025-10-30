#include<stdio.h>
int main(){
    int arr[3],max,i,min;
    printf("enter elements of array:");
    for(i=0;i<3;i++){
        scanf("%d",&arr[i]);
    }
    max=arr[0];
    min=arr[0];
    for(i=1;i<3;i++){
        if(arr[i]>max){
            max=arr[i];
        }
        if(arr[i]<min){
            min=arr[i];
        }
    }
    printf("maximum=%d\n",max);
    printf("minimum=%d\n",min);
    return 0;
}