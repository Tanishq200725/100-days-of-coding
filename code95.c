//Reverse each word in a sentence without changing the word order
#include <stdio.h>
#include <string.h>
int main(){                                                     

    char sentence[200];
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    sentence[strcspn(sentence, "\n")] = 0; 

    int start = 0, end = 0, len = strlen(sentence);
    char result[200] = "";

    while (end <= len) {
        if (sentence[end] == ' ' || sentence[end] == '\0') {
            for (int i = end - 1; i >= start; i--) {
                strncat(result, &sentence[i], 1);
            }
            if (sentence[end] == ' ') {
                strcat(result, " ");
            }
            start = end + 1;
        }
        end++;
    }

    printf("Reversed words sentence: %s\n", result);

    return 0;
}