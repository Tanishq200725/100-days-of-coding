/*Write a C program that opens an existing file (e.g., info.txt) and reads its contents using fgets(). The program should print all the lines to the console until EOF (end of file) is reached.*/
#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *file;
    char buffer[256];
    file = fopen("info.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }
    fclose(file);
    return EXIT_SUCCESS;
}