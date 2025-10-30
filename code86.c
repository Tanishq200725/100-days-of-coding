//Count spaces, digits, and special characters in a string.
#include <stdio.h>
#include <string.h>
int main(){
    char str[100];
    int i,countSpaces=0,countDigits=0,countSpecial=0;
printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;
    for(i=0; str[i]!='\0'; i++){
        if(str[i]==' ')
            countSpaces++;
        else if(str[i]>='0' && str[i]<='9')
            countDigits++;
        else if((str[i]>='!' && str[i]<='/') || (str[i]>=':' && str[i]<='@') || 
                (str[i]>='[' && str[i]<='`') || (str[i]>='{' && str[i]<='~'))
            countSpecial++;
    }
    printf("Spaces: %d\n", countSpaces);
    printf("Digits: %d\n", countDigits);
    printf("Special Characters: %d\n", countSpecial);
    return 0;
}