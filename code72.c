//Find the sum of each row of a matrix and store it in an array.
#include <stdio.h>
int main(){

    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    int rowSums[3] = {0};

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            rowSums[i] += matrix[i][j];
        }
    }

    printf("Sum of each row:\n");
    for(int i = 0; i < 3; i++){
        printf("Row %d: %d\n", i + 1, rowSums[i]);
    }

    return 0;



}