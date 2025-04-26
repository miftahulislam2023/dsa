#include <stdio.h>

// Function to traverse and print a matrix
void traverseMatrix(int matrix[][3], int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to multiply two matrices
void multiplyMatrices(int firstMatrix[][3], int secondMatrix[][3], int result[][3], int rows1, int cols1, int cols2)
{
    // Initialize result matrix with zeros
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            result[i][j] = 0;
        }
    }

    // Multiply matrices
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            for (int k = 0; k < cols1; k++)
            {
                result[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }
}

int main()
{
    int i, j;
    int matrix_A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    int matrix_I[3][3] = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}};

    printf("Matrix A:\n");
    traverseMatrix(matrix_A, 3, 3);

    printf("\nIdentity Matrix:\n");
    traverseMatrix(matrix_I, 3, 3);

    int matrix_Result[3][3];

    // Multiply matrices using the function
    multiplyMatrices(matrix_A, matrix_I, matrix_Result, 3, 3, 3);

    // Print the result matrix
    printf("\nResult matrix:\n");
    traverseMatrix(matrix_Result, 3, 3);

    return 0;
}