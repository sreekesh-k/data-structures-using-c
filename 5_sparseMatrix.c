#include <stdio.h>

int main()
{
    int r, c;
    printf("Enter the number of rows in the matrix: ");
    scanf("%d", &r);
    printf("Enter the number of columns in the matrix: ");
    scanf("%d", &c);

    int matrix[r][c];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    int nonZero = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (matrix[i][j] != 0)
            {
                nonZero++;
            }
        }
    }

    int sparseMatrix[nonZero][3];
    int k = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (matrix[i][j] != 0)
            {
                sparseMatrix[k][0] = i;
                sparseMatrix[k][1] = j;
                sparseMatrix[k][2] = matrix[i][j];
                k++;
            }
        }
    }
    printf("Sparse Matrix Representation:\n");
    for (int i = 0; i < nonZero; i++)
    {
        printf("%d\t%d\t%d\n", sparseMatrix[i][0], sparseMatrix[i][1], sparseMatrix[i][2]);
    }

    return 0;
}