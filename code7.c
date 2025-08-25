// write a program to swap 2 numbers without using third variable.

#include<stdio.h>
int main() {
int a,b;
printf("enter a:");
scanf("%d", &a);
printf("enter b:");
scanf("%d",&b);
printf("\nBefore swapping:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    a = a + b;
    b + a - b;
    a = a - b;
    printf("\nAfter swapping:\n");
    printf("a = %d\n", b);
    printf("b = %d\n", a);
return 0;
}
