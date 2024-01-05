#include <stdio.h>
#include <stdlib.h>

int **mem_allocate(int n) {
    int **M, i;
    M = (int **)calloc(n, sizeof(int *));
    for (int i = 0;i < n;i++) {
        M[i] = (int *)calloc(n, sizeof(int));
    }
    return M;
}

void input_matrix(int **mat, int n) {
    printf("Enter the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

int subtract(int rs, int cs, int re, int ce, int **A, int **B, int **C) {
    if (re - rs == 1) {
        return C[rs][cs] = A[rs][cs] + B[rs][cs];

    }
    subtract(rs, cs, (rs + re) / 2, (cs + ce) / 2, A, B, C);
    subtract(rs, (cs + ce) / 2, (rs + re) / 2, ce, A, B, C);
    subtract((rs + re) / 2, cs, re, (cs + ce) / 2, A, B, C);
    subtract((rs + re) / 2, (cs + ce) / 2, re, ce, A, B, C);
}

void display_matrix(int **mat, int n) {
    printf("Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, i, j, **A, **B, **C;
    printf("Enter the size of matrix of orden n:");
    scanf("%d", &n);

    A = mem_allocate(n);
    B = mem_allocate(n);
    C = mem_allocate(n);

    input_matrix(A, n);
    input_matrix(B, n);

    subtract(0, 0, n, n, A, B, C);

    printf("\nFirst\n");
    display_matrix(A, n);
    printf("\nSecond\n");
    display_matrix(B, n);
    printf("\nResultant\n");
    display_matrix(C, n);
}