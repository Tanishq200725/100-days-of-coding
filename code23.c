//Write a program to calculate a library fine based on late days.
#include<stdio.h>
int main(){
int days,fine,total;
printf("enter days:");
scanf("%d",&days);
fine = 8;
if(days<30){
total = days * fine;
printf("%d",total);
}
else{
    printf("membership cancelled");
}
return 0;







}