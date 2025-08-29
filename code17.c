//Write a program to find the roots of a quadratic equation and categorize them.

#include<stdio.h>
#include<math.h>
int main() {
float discriminant,root1,root2,realPart,imaginaryPart,a,b,c;
printf("Enter coefficients a, b and c: ");
scanf("%f %f %f", &a, &b, &c);
discriminant = b * b - 4 *a *c;
if (discriminant>0){
    root1 = - b + sqrt(discriminant)/(2 *a);
root2 = - b + sqrt(discriminant)/2 * a;

printf(" roots are real\n");
printf("root1 = %.2f,root2 = %.2f\n",root1,root2);
}
else if(discriminant=0){
    root1 = - b + sqrt(discriminant)/(2 *a);
    root1=root2;
    printf("roots are real");
    printf("root1 = %.2f,root2 = %.2f\n",root1,root2);
}
else {
    realPart = -b / (2 * a);
        imaginaryPart = sqrt(-discriminant) / (2 * a);
        printf("Roots are imaginary.\n");
        printf("Root1 = %.2f + %.2fi , Root2 = %.2f - %.2fi\n",
               realPart, imaginaryPart, realPart, imaginaryPart);
    }
}


