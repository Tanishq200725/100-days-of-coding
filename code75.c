//Check if a matrix is symmetric.
#include <stdio.h>
int main(){
    int n,m,i,j;
    printf("Enter number of rows and columns: ");
    scanf("%d %d",&n,&m);
    if(n!=m){
        printf("Matrix is not symmetric.\n");
        return 0;
    }
    int matrix[n][m];
    printf("Enter matrix elements:\n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    int is_symmetric=1;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(matrix[i][j]!=matrix[j][i]){
                is_symmetric=0;
                break;
            }
        }
        if(!is_symmetric){
            break;
        }
    }
}