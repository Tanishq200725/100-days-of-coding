//Find the longest word in a sentence.
#include <stdio.h>
#include <string.h> 
int main(){
    char str[100], longest[100];
    int i, length = 0, maxLength = 0, start = 0, end = 0;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    for(i = 0; ; i++){
        if(str[i] == ' ' || str[i] == '\0' || str[i] == '\n'){
            end = i;
            length = end - start;
            if(length > maxLength){
                maxLength = length;
                strncpy(longest, &str[start], length);
                longest[length] = '\0';
            }
            start = i + 1;
        }
        if(str[i] == '\0' || str[i] == '\n'){
            break;
        }
    }

    printf("The longest word is: %s\n", longest);
    return 0;
}
