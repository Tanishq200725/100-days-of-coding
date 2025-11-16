/*Read a text file and count how many vowels and consonants are in the file. Ignore digits and special characters.*/
#include <stdio.h>
int main() {
    FILE *file;
    char filename[100];
    char ch;
    int vowels = 0, consonants = 0;
    printf("Enter the filename: ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        return 1;
    }
    while ((ch = fgetc(file)) != EOF) {
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
            char lower_ch = (ch >= 'A' && ch <= 'Z') ? ch + 32 : ch;    
            if (lower_ch == 'a' || lower_ch == 'e' || lower_ch == 'i' || lower_ch == 'o' || lower_ch == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }
    fclose(file);
    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);

    return 0;
}