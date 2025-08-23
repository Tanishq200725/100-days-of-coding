// Write a program to calculate the area and circumference of a circle given its radius.

#include<stdio.h>
#define pi 3.14
int main() {
float r;
printf("enter r :");
scanf("%f", &r);
float area = pi * r * r;
float circumference = 2 * pi * r;
printf("area: %f\n", area);
printf("circumference: %f\n", circumference);
return 0;


}
