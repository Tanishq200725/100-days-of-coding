//Print the initials of a name.

#include <stdio.h>
#include <string.h>
int main() {
    char name[100];
    printf("Enter your full name: ");
    fgets(name, sizeof(name), stdin);  
    printf("Initials: ");
    int len = strlen(name);
    for (int i = 0; i < len; i++) {
        if (i == 0 || (name[i - 1] == ' ' && name[i] != ' ')) {
            printf("%c", name[i]);
        }
    }
    printf("\n");
    return 0;
}