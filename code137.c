/*Create an enum for user roles (ADMIN, USER, GUEST) and display messages based on role.*/
#include <stdio.h>
enum UserRole {
    ADMIN,
    USER,
    GUEST
};
int main() {
    enum UserRole role;
    int choice;

    printf("Select user role:\n0. ADMIN\n1. USER\n2. GUEST\n");
    scanf("%d", &choice);
    role = (enum UserRole)choice;

    switch (role) {
        case ADMIN:
            printf("Welcome, Admin! You have full access.\n");
            break;
        case USER:
            printf("Welcome, User! You have limited access.\n");
            break;
        case GUEST:
            printf("Welcome, Guest! You have minimal access.\n");
            break;
        default:
            printf("Invalid role selected!\n");
            break;
    }
    return 0;
}   