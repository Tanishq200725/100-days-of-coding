//Remove all vowels from a string.
#include <stdio.h>
#include <string.h>
int main(){
    char str[100], result[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    int len = strlen(str);
    int j = 0;
    for(int i = 0; i < len; i++){
        if(!(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' ||
             str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U')){
            result[j++] = str[i];
        }
    }
    result[j] = '\0'; 
    printf("String after removing vowels: %s", result);
    return 0;
}