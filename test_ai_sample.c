// Program to calculate factorial of a number using recursion
// This program demonstrates recursive function implementation

#include <stdio.h>
#include <stdlib.h>

// Function to calculate factorial recursively
// Parameters: n - the number to calculate factorial for
// Returns: factorial of n
long long calculateFactorial(int n) {
    // Base case: factorial of 0 or 1 is 1
    if (n <= 1) {
        return 1;
    }
    
    // Recursive case: n! = n * (n-1)!
    return n * calculateFactorial(n - 1);
}

// Function to validate user input
// Parameters: num - the number to validate
// Returns: 1 if valid, 0 if invalid
int validateInput(int num) {
    if (num < 0) {
        fprintf(stderr, "Error: Negative numbers are not allowed.\n");
        return 0;
    }
    
    if (num > 20) {
        fprintf(stderr, "Error: Number too large (maximum is 20).\n");
        return 0;
    }
    
    return 1;
}

// Main function
int main() {
    int number;
    long long result;
    
    // Display program information
    printf("=================================\n");
    printf("Factorial Calculator\n");
    printf("=================================\n\n");
    
    // Get user input
    printf("Enter a positive integer: ");
    
    // Check if input is valid
    if (scanf("%d", &number) != 1) {
        fprintf(stderr, "Error: Invalid input. Please enter an integer.\n");
        return EXIT_FAILURE;
    }
    
    // Validate the input
    if (!validateInput(number)) {
        return EXIT_FAILURE;
    }
    
    // Calculate factorial
    result = calculateFactorial(number);
    
    // Display the result
    printf("\nFactorial of %d = %lld\n", number, result);
    printf("=================================\n");
    
    return EXIT_SUCCESS;
}
