//Perform diagonal traversal of a matrix.
#include <stdio.h>
int main() {
    int matrix[10][10], rows, cols, i, j, k;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);
    printf("Enter matrix elements:\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("Diagonal Traversal of the matrix:\n");
    for(k = 0; k <= rows + cols - 2; k++) {
        for(i = 0; i <= k; i++) {
            j = k - i;
            if(i < rows && j < cols) {
                printf("%d ", matrix[i][j]);
            }
        }
    }
    return 0;
}