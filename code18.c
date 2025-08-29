//write a program to assign grades based on a percentage input.

#include<stdio.h>
int main(){
float percentage;
printf("enter percentage:");
scanf("%f",&percentage);
if(percentage>=30 && percentage<=40)
{
    printf("your grade is d\n");
    printf("improvement is much required");
}
else if(percentage>40 && percentage<=60)
{
    printf("your grade is c\n");
    printf("more efforts are needed");
}
else if(percentage>60 && percentage<=80)
{
    printf("your grade is b\n");
    printf("nice attempt");
}
else if(percentage>80 && percentage<=95)
{
    printf("your grade is a\n");
    printf("well done");
}
else if(percentage>95 && percentage<=100)
{
    printf("your grade is a++\n");
    printf("outstanding performance");
}
else{
    printf("you are fail");
}
return 0;
}