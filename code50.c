//Write a program to print the following pattern:
//*****
//****
//***
//**
//*
#include<stdio.h>
int main(){
int n,i,j;
printf("enter number of rows:");
scanf("%d",&n);
for(i=n;i>=1;i--){
    for(j=1;j<=i;j++){
        printf("*");
    }
    printf("\n");
}
return 0;




}