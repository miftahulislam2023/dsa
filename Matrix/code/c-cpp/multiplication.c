#include <stdio.h>

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

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", matrix_A[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", matrix_I[i][j]);
        }
        printf("\n");
    }

    int matrix_Result[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                matrix_Result[i][j] += matrix_A[i][k] * matrix_I[k][j];
            }
        }
    }

    // Print the result matrix
    printf("\nResult matrix:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", matrix_Result[i][j]);
        }
        printf("\n");
    }
}