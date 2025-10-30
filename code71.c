//Find the sum of all elements in a matrix.
#include <stdio.h>
int main(){ 
    int mat[3][3];
    printf("Enter elements of 3x3 matrix:\n");  
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    int sum=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            sum += mat[i][j];
        }
    }
    printf("The sum of all elements in the matrix is: %d\n", sum);
    return 0;
}