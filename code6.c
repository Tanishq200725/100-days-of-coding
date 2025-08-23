// Write a program to swap two numbers using a third variable.
#include <stdio.h>

int main() {
    int a, b, temp;


    printf("Enter a: ");
    scanf("%d", &a);
    printf("Enter b: ");
    scanf("%d", &b);

    printf("\nBefore swapping:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    temp = a; 
    a = b;    
    b = temp; 

    printf("\nAfter swapping:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    return 0;
}

