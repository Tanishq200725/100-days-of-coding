// Write a program to calculate simple and compound interest for given principal, rate, and time.

#include<stdio.h>
#include<math.h>
int main() {
int time,n;
float principle,rate,si,ci;
printf("enter time:");
scanf("%d", &time);
printf("enter principle:");
scanf("%f", &principle);

printf("enter rate:");
scanf("%f", &rate);
si = (principle * rate * time) / 100;
printf("si is: %f\n", si);
printf("enter n:");
scanf("%d",&n);
ci = principle * pow (1 + rate / (100 * n), time) ;
printf("ci is: %f\n", ci);
return 0;



}
