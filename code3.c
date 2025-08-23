// Write a program to calculate the area and perimeter of a rectangle given its length and breadth.

#include<stdio.h>
int main() {
    float a,b;
    printf("enter a:");
    scanf("%f", &a);
    printf("enter b:");
    scanf("%f",&b);
    float area = a * b;
    float perimeter = 2 * (a + b);
    printf("area: %f\n", area);
    printf("perimeter: %f\n", perimeter);
    return 0;
    

}