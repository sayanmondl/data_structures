#include <stdio.h>
int main() {
    int rows, cols;
    printf("Enter rows & columns of the matrices: ");
    scanf("%d%d", &rows, &cols);

    int mat1[rows][cols], mat2[rows][cols];

    printf("Enter the 1st matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("Enter the 2nd matrix: \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }
    printf("\n\n");

    printf("(sum of matrices=)\t\n\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d", mat1[i][j] + mat2[i][j]);
            printf("\t");
        }
        printf("\n\n");
    }

    return 0;
}