// Write a program to convert temperature from Celsius to Fahrenheit.

#include<stdio.h>
int main() {
float celsius;
printf("enter celsius:");
scanf("%f",&celsius);
float fahrenhiet = (celsius * 9 / 5) + 32;
printf("fahrenhiet: %f\n", fahrenhiet);
return 0;

}

