//Write a program to find the sum of digits of a number.

#include<stdio.h>
int main(){
int temp,rem,n,i,sum=0;
printf("enter number:");
scanf("%d",&n);
i!=0;
while(n>=0){
    rem=n%10;
    sum=sum+rem;
    n=n/10;
}
printf("%d\n",sum);
return 0;

}