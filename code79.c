//Multiply two matrices
#include <stdio.h>
int main(){
    int m,n,i,j;
    printf("Enter number of rows and columns: ");
    scanf("%d%d",&m,&n);
    int a[m][n],b[m][n],mul[m][n];
    printf("Enter elements of first matrix:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter elements of second matrix:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&b[i][j]);
        }
    }
    for(i=0;i<m;i++){   
        for(j=0;j<n;j++){
            mul[i][j]=a[i][j]*b[i][j];
        }
    }
    printf("Resultant Matrix:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d ",mul[i][j]);
        }
        printf("\n");
    }
    return 0;
}