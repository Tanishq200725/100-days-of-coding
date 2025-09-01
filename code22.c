//Write a program to find profit or loss percentage given cost price and selling price.

#include<stdio.h>
int main(){
float sellingPrice,costPrice,profit,loss,percentage;
printf("enter sellingPrice , costPrice");
scanf("%f %f",&sellingPrice,&costPrice);
if(sellingPrice>costPrice){
    profit = sellingPrice-costPrice;
    percentage = (profit/costPrice)*100;
    printf("profit");
    printf("%f\n,percentage");
}
  
else if(sellingPrice<costPrice){
    loss = costPrice-sellingPrice;
    percentage = (loss/costPrice)*100;
    printf("loss ");
    printf("%f\n",percentage);
}
else{
    printf("no profit no loss");
}
return 0;



}