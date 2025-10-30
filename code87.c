//Replace spaces with hyphens in a string
#include <stdio.h>
#include <string.h>
int main(){
    char str[100];
    int i;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;
    for(i=0; str[i]!='\0'; i++){
        if(str[i]==' ')
            str[i]='-';
    }
    printf("Modified string: %s\n", str);
    return 0;
}