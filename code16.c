// Write a program to input three numbers and find the largest among them using if–else.

#include<stdio.h>
int main() {
int a,b,c;
printf("enter a:\n");
scanf("%d",&a);
printf("enter b:\n");
scanf("%d",&b);
printf("enter c:\n");
scanf("%d", &c);
if(a > b && a > c){
    printf("%d is the largest", a);
}
else if(b > a && b > c){
    printf("%d is the largest", b);
}
else if( c > a && c > b) {
    printf("%d is the largest", c);
}
return 0;


}