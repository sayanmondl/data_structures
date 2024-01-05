#include <stdio.h>
#include <stdlib.h>

int **mem_allocate(int n)
{
    int **M, i;
    M = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        M[i] = (int *)calloc(n, sizeof(int));
    }
    return M;
}

void inputMatrix(int **mat, int n)
{
    printf("Enter the matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
}

int Mat_Add_Rec(int rs, int cs, int re, int ce, int **A, int **B, int **C)
{
    static int i = 0;
    static int j = 0;
    if (re - rs == 1)
    {
        return C[rs][cs] = A[rs][cs] + B[rs][cs];
    }
    Mat_Add_Rec(rs, cs, (rs + re) / 2, (cs + ce) / 2, A, B, C);
    Mat_Add_Rec(rs, (cs + ce) / 2, (rs + re) / 2, ce, A, B, C);
    Mat_Add_Rec((rs + re) / 2, cs, re, (cs + ce) / 2, A, B, C);
    Mat_Add_Rec((rs + re) / 2, (cs + ce) / 2, re, ce, A, B, C);
}

void displayMatrix(int **mat, int n)
{
    printf("Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

int main()
{

    int n, i, j, **A, **B, **C;
    scanf("%d", &n);

    A = mem_allocate(n);
    B = mem_allocate(n);
    C = mem_allocate(n);

    inputMatrix(A, n);
    inputMatrix(B, n);

    Mat_Add_Rec(0, 0, n, n, A, B, C);
    displayMatrix(A, n);
    displayMatrix(B, n);
    displayMatrix(C, n);
}