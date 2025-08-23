// Write a program to swap two numbers using a third variable.
#include <stdio.h>

int main() {
    int a, b, temp;

    // Get input from the user
    printf("Enter a: ");
    scanf("%d", &a);
    printf("Enter b: ");
    scanf("%d", &b);

    printf("\nBefore swapping:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    // Swap logic using a third variable
    temp = a; // Store the value of 'a' in 'temp'
    a = b;    // Assign the value of 'b' to 'a'
    b = temp; // Assign the value of 'temp' (original 'a') to 'b'

    printf("\nAfter swapping:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    return 0;
}
