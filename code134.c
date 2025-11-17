/*Define an enum with SUCCESS, FAILURE, and TIMEOUT, and print messages accordingly.*/
#include <stdio.h>
typedef enum {
    SUCCESS,
    FAILURE,
    TIMEOUT
} Status;
int main() {
    Status currentStatus = TIMEOUT;

    switch (currentStatus) {
        case SUCCESS:
            printf("Operation completed successfully.\n");
            break;
        case FAILURE:
            printf("Operation failed.\n");
            break;
        case TIMEOUT:
            printf("Operation timed out.\n");
            break;
        default:
            printf("Unknown status.\n");
            break;
    }

    return 0;
}