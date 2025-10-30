//Count vowels and consonants in a string.
#include<stdio.h>
int main(){
    char str[100],ch;
    int countVOwel=0,countConsonant=0;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    for(int i=0; str[i]!='\0'; i++){
        ch = str[i];
        if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z')){
            if(ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U' || 
               ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
                countVOwel++;
            } else {
                countConsonant++;
            }
        }
    }
    printf("Number of vowels: %d\n", countVOwel);
    printf("Number of consonants: %d\n", countConsonant);
    return 0;
}


