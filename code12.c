// Write a program to input an integer and check whether it is positive, negative or zero using nested if–else.

#include<stdio.h>
int main() {
int n;
printf("enter n:");
scanf("%d",&n);
if(n < 0){
    printf("n is negative");
}
else if (n >0){
    printf("n is positive");
}
else{
    printf("the number is 0");
}
return 0;




}