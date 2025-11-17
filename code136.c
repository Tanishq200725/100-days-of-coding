/*Use enum to represent menu choices (ADD, SUBTRACT, MULTIPLY) and perform operations using switch.*/
#include <stdio.h>
enum Operation {
    ADD = 1,
    SUBTRACT,
    MULTIPLY
};
int main() {
    int choice, a, b;
    printf("Select operation:\n1. ADD\n2. SUBTRACT\n3. MULTIPLY\n");
    scanf("%d", &choice);
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    switch (choice) {
        case ADD:
            printf("Result: %d\n", a + b);
            break;
        case SUBTRACT:
            printf("Result: %d\n", a - b);
            break;
        case MULTIPLY:
            printf("Result: %d\n", a * b);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
    return 0;
}