/*Write a program to take a string input. Change it to sentence case.*/
#include<stdio.h>
#include<string.h>
int main(){
    FILE *fp;
    char str[100];
    fp=fopen("code120.txt","r");
    fgets(str,100,fp);
    str[0]=str[0]-32;
    printf("String in sentence case: %s",str);
    fclose(fp);
    return 0;
}