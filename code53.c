//Write a program to print the following pattern:
/*
***
*****
*******
*********
*******
*****
***/
#include <stdio.h>
int main() {
    int i, j, n;

    printf("Enter number of rows (odd number): ");
    scanf("%d", &n);

    // Upper half (including middle row)
    for(i = 3; i <= n; i += 2) {
        for(j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

    // Lower half
    for(i = n - 2; i >= 3; i -= 2) {
        for(j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}

