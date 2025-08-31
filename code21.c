//Write a program to display the month name and number of days using switch-case for a given month number.

#include<stdio.h>
int main()
{
int month,number_Of_Days_In_Year;
printf("enter month:");
scanf("%d",&month);
switch(month)
{
case 1:printf("month is january\n");
printf("number of days:31");
break;
case 2:printf("month is february\n");
printf("enter number of days:");
scanf("%d",&number_Of_Days_In_Year);

if(number_Of_Days_In_Year==366)
{
    printf("number of days:29");
}
else{
    printf("number of days:28");
}
break;
case 3:printf("the month is march\n");
printf("number of days :31");
break;
case 4:printf("month is april\n");
printf("number of days:30");
break;
case 5:printf("month is may\n");
printf("number of days:31");
break;
case 6:printf("month is june\n");
printf("number of days:30");
break;
case 7:printf("month is july\n");
printf("number of days:31");
break;
case 8:printf("month is august\n");
printf("number of days:31");
break;
case 9:printf("month is september\n");
printf("number of days:30");
break;
case 10:printf("month is october\n");
printf("number of days:31");
break;
case 11:printf("month is november\n");
printf("number of days:30");
break;
case 12:printf("month is december\n");
printf("number of days:31");
break;
default:printf("enter your choice from 1-12");
}

return 0;


}






