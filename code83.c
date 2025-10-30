//onvert a lowercase string to uppercase without using built-in functions.
#include<stdio.h>
int main(){
    char str[100], ch;
    printf("Enter a lowercase string: ");
    fgets(str, sizeof(str), stdin);
    for(int i=0; str[i]!='\0'; i++){
        ch = str[i];
        if(ch >= 'a' && ch <= 'z'){
            str[i] = ch -32;
        }
    }
    printf("Uppercase string: %s", str);
    return 0;
}
