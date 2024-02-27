#include <stdio.h>
#include <stdlib.h>

int **allocate(int **mat, int n) {
    mat = (int **)calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++) {
        mat[i] = (int *)calloc(n, sizeof(int));
    }
    return mat;
}

void get_mat(int **mat, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("enter number:");
            scanf("%d", &mat[i][j]);
        }
    }
}

void display(int **mat, int n) {
    for (int i = 0; i < n;i++) {
        for (int j = 0; j < n; j++) {
            printf("%d  ", mat[i][j]);
        }
        printf("\n");
    }
}

void mul(int **A, int **B, int **C, int Ai, int Aj, int Bi, int Bj, int Ci, int Cj, int n) {
    if (n == 2) {
        C[Ci][Cj] += A[Ai][Aj] * B[Bi][Bj] + A[Ai][Aj + 1] * B[Bi + 1][Bj];
        C[Ci][Cj + 1] += A[Ai][Aj] * B[Bi][Bj + 1] + A[Ai][Aj + 1] * B[Bi + 1][Bj + 1];
        C[Ci + 1][Cj] += A[Ai + 1][Aj] * B[Bi][Bj] + A[Ai + 1][Aj + 1] * B[Bi + 1][Bj];
        C[Ci + 1][Cj + 1] += A[Ai + 1][Aj] * B[Bi][Bj + 1] + A[Ai + 1][Aj + 1] * B[Bi + 1][Bj + 1];
    }
    mul(A, B, C, Ai, Aj, Bi, Bj, Ci, Cj, n / 2);
    mul(A, B, C, Ai, n / 2, n / 2, Bj, Ci, Cj, n / 2);
    mul(A, B, C, Ai, Aj, Bi, n / 2, Ci, n / 2, n / 2);
    mul(A, B, C, Ai, n / 2, n / 2, n / 2, Ci, n / 2, n / 2);
    mul(A, B, C, n / 2, Aj, Bi, Bj, n / 2, Cj, n / 2);
    mul(A, B, C, n / 2, n / 2, n / 2, Bj, n / 2, Cj, n / 2);
    mul(A, B, C, n / 2, Aj, Bi, n / 2, n / 2, n / 2, n / 2);
    mul(A, B, C, n / 2, n / 2, n / 2, n / 2, n / 2, n / 2, n / 2);
}

int main() {
    int **A, **B, **C;
    int n;
    printf("enter n(must be power of 2):");
    scanf("%d", &n);
    A = allocate(A, n);
    B = allocate(B, n);
    C = allocate(C, n);
    get_mat(A, n);
    get_mat(B, n);
    mul(A, B, C, 0, 0, 0, 0, 0, 0, n);
    display(C, n);
}