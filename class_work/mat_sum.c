#include <stdio.h>
#include <stdlib.h>

void input(int **mat, int row, int col);
int **allocate_memory(int row, int col);
void display(int **mat, int row, int col);
void sum(int **mat1, int **mat2, int **mat3, int row, int col);

int main()
{
    int row = 3;
    int col = 3;
    int **mat1, **mat2, **mat3;
    mat1 = allocate_memory(row, col);
    mat2 = allocate_memory(row, col);
    mat3 = allocate_memory(row, col);

    input(mat1, row, col);
    input(mat2, row, col);

    sum(mat1, mat2, mat3, row, col);
    display(mat3, row, col);

    return 0;
}

void input(int **mat, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
}

int **allocate_memory(int row, int col)
{
    int **mat;
    mat = (int **)calloc(row, sizeof(int *));
    for (int i = 0; i < row; i++)
    {
        mat[i] = (int *)calloc(col, sizeof(int));
    }
    return mat;
}

void display(int **mat, int row, int col)
{
    printf("(sum of matrices=)\t\n\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d", mat[i][j]);
            printf("\t");
        }
        printf("\n\n");
    }
}

void sum(int **mat1, int **mat2, int **mat3, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            mat3[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}