//Print initials of a name with the surname displayed in full.
#include <stdio.h>
#include <string.h>
int main() {
    char name[100];
    printf("Enter your full name: ");
    fgets(name, sizeof(name), stdin);  
    printf("Initials with surname: ");
    int len = strlen(name);
    int i;
    for (i = 0; i < len; i++) {
        if (i == 0 || (name[i - 1] == ' ' && name[i] != ' ')) {
            int j = i;
            while (j < len && name[j] != ' ') {
                j++;
            }
            if (j < len) { 
                printf("%c. ", name[i]);
            } else { 
                break;
            }
        }
    }
    for (; i < len; i++) {
        printf("%c", name[i]);
    }
    printf("\n");
    return 0;
}