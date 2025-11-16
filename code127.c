/*Write a program that reads text from input.txt, converts all lowercase letters to uppercase, and writes the result to output.txt.*/
#include <stdio.h>
int main() {
    FILE *inputFile = fopen("input.txt", "r");
    FILE *outputFile = fopen("output.txt", "w");
    if (inputFile == NULL || outputFile == NULL) {
        perror("Error opening file");
        return 1;
    }
    int ch;
    while ((ch = fgetc(inputFile)) != EOF) {
        if (ch >= 'a' && ch <= 'z') {
            ch = ch - ('a' - 'A');
        }
        fputc(ch, outputFile);
    }
    fclose(inputFile);
    fclose(outputFile);
    return 0;
}