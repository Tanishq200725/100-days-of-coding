//Count frequency of a given character in a string.
#include <stdio.h>
#include <string.h>
int main(){
    char str[100];
    char ch;
    int i,count=0;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    printf("Enter a character to find frequency: ");
    scanf("%c", &ch);
    for(i=0; str[i]!='\0'; i++){
        if(str[i]==ch){
            count++;
        }
    }
    printf("Frequency of '%c' in the given string is: %d\n", ch, count);
    return 0;
}