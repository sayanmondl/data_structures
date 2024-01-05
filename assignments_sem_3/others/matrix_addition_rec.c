#include <stdio.h>
#include <stdlib.h>
int **allocate_memory(int row, int col);
void free_memory(int **mat, int row);
void get_input(int **mat, int row, int col);
void display(int **mat, int row, int col);
void sum(int **mat1, int **mat2, int **mat3, int row, int col);

int main() {
    int **mat1, **mat2, **mat3, row, col;
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d%d", &row, &col);

    mat1 = allocate_memory(row, col);
    mat2 = allocate_memory(row, col);
    mat3 = allocate_memory(row, col);

    printf("Enter elements of first matrix: \n");
    get_input(mat1, row, col);

    printf("Enter elements of second matrix: \n");
    get_input(mat2, row, col);

    sum(mat1, mat2, mat3, row, col);

    printf("Sum of the matrices: \n");
    display(mat3, row, col);

    free_memory(mat1, row);
    free_memory(mat2, row);
    free_memory(mat3, row);

    return 0;
}

void sum(int **mat1, int **mat2, int **mat3, int row, int col) {
    static int i = 0;
    static int j = 0;
    if (j == col) {
        i = i + 1;
        j = 0;
    }

    if (i == row) {
        i = 0;
        j = 0;
        return;
    }

    mat3[i][j] = mat1[i][j] + mat2[i][j];
    j = j + 1;
    sum(mat1, mat2, mat3, row, col);
}

int **allocate_memory(int row, int col) {
    int **mat;
    mat = (int **)calloc(row, sizeof(int *));
    for (int i = 0; i < row; i++) {
        mat[i] = (int *)calloc(col, sizeof(int));
    }
    return mat;
}

void get_input(int **mat, int row, int col) {
    printf("Enter the matrix:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

void display(int **mat, int row, int col) {
    printf("Matrix:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

void free_memory(int **mat, int row) {
    for (int i = 0; i < row; i++) {
        free(mat[i]);
    }
    free(mat);
}