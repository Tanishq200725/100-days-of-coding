//Write a program to find the HCF (GCD) of two numbers

#include<stdio.h>
int main(){
int i,n,a,hcf;
printf("enter n,a:");
scanf("%d %d",&n,&a);
for(i=1;i<=a && i<=n;i++){
    if(a%i==0 && n%i==0){
        printf("%d\n",hcf);
        hcf=i;

    }

printf("HCF (GCD) of %d and %d is: %d\n", a, n, hcf);
return 0;

}
}