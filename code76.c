//Check if the elements on the diagonal of a matrix are distinct.
#include <stdio.h>
int main(){
    int matrix[10][10], n, i, j, k, flag = 0;
    printf("Enter the order of the square matrix (max 10): ");
    scanf("%d", &n);
    printf("Enter the elements of the matrix:\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    for(i = 0; i < n; i++){
        for(j = i + 1; j < n; j++){
            if(matrix[i][i] == matrix[j][j]){
                flag = 1;
                break;
            }
        }
        if(flag){
            break;
        }
    }
    if(flag){
        printf("The diagonal elements are not distinct.\n");
    } else {
        printf("The diagonal elements are distinct.\n");
    }
    return 0;
}