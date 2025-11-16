/*Take two filenames from the user – a source file and a destination file. Copy all the content from the source file to the destination file using fgetc() and fputc().*/
#include <stdio.h>
int main() {
    char sourceFileName[100], destFileName[100];
    FILE *sourceFile, *destFile;
    int ch;
    printf("Enter source file name: ");
    scanf("%s", sourceFileName);
    printf("Enter destination file name: ");
    scanf("%s", destFileName);

    sourceFile = fopen(sourceFileName, "r");
    if (sourceFile == NULL) {
        printf("Could not open source file %s\n", sourceFileName);
        return 1;
    }
    destFile = fopen(destFileName, "w");
    if (destFile == NULL) {
        printf("Could not open destination file %s\n", destFileName);
        fclose(sourceFile);
        return 1;
    }
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destFile);
    }
    printf("Content copied from %s to %s successfully.\n", sourceFileName, destFileName);
    fclose(sourceFile);
    fclose(destFile);

    return 0;
}