/*Write a program to take two strings s and t as inputs (assume all characters are lowercase). The task is to determine if s and t are valid anagrams, meaning they contain the same characters with the same frequencies. Print "Anagram" if they are, otherwise "Not Anagram".
*/  #include <stdio.h>
#include <string.h>
int main() {
    char s[100], t[100];
    int countS[26] = {0}, countT[26] = {0};
    printf("Enter first string: ");
    scanf("%s", s);
    printf("Enter second string: ");
    scanf("%s", t);
    for(int i = 0; s[i] != '\0'; i++) {
        countS[s[i] - 'a']++;
    }
    for(int i = 0; t[i] != '\0'; i++) {
        countT[t[i] - 'a']++;
    }
    int isAnagram = 1;
    for(int i = 0; i < 26; i++) {
        if(countS[i] != countT[i]) {
            isAnagram = 0;
            break;
        }
    }
    if(isAnagram) {
        printf("Anagram\n");
    } else {
        printf("Not Anagram\n");
    }
    
    return 0;
}
