//Write a program to print all the prime numbers from 1 to n.
#include <stdio.h>
int main() {
    int i, j, n;

    printf("Enter range: ");
    scanf("%d", &n);

    printf("Prime numbers from 1 to %d are:\n", n);

    for(i = 2; i <= n; i++) {
        for(j = 2; j <= i; j++) {
            if(i % j == 0)
                break;   
        }
        if(i == j) {   
            printf("%d\n", i);
        }
    }

    return 0;
}









