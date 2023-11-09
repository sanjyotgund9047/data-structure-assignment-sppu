/*Implement a program for simple transpose of the matrix*/

#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10

void transposeMatrix(int original[MAX_ROWS][MAX_COLS], int transposed[MAX_COLS][MAX_ROWS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = original[i][j];
        }
    }
}

void displayMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int originalMatrix[MAX_ROWS][MAX_COLS];
    int transposedMatrix[MAX_COLS][MAX_ROWS];
    int rows, cols;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &originalMatrix[i][j]);
        }
    }

    printf("Original Matrix:\n");
    displayMatrix(originalMatrix, rows, cols);

    transposeMatrix(originalMatrix, transposedMatrix, rows, cols);

    printf("Transposed Matrix:\n");
    displayMatrix(transposedMatrix, cols, rows);

    return 0;
}

/*Outputs
Enter the number of rows: 3
Enter the number of columns: 4
Enter the elements of the matrix:
1 2 3 4
5 6 7 8
9 10 11 12
Original Matrix:
1       2       3       4
5       6       7       8
9       10      11      12
Transposed Matrix:
1       5       9
2       6       10
3       7       11
4       8       12

*/