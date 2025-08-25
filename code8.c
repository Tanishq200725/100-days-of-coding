// write a program to find and display sum of n natural numbers.

#include<stdio.h>
int main() {
int n;
printf("enter n:");
scanf("%d",&n);
int sum = n * (n + 1) / 2;
printf("sum is : %d\n", sum);
return 0;

}