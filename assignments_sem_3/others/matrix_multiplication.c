#include <stdio.h>
int main() {
    int r1, c1, r2, c2;
    printf("Enter rows & columns of the 1st matrix: ");
    scanf("%d%d", &r1, &c1);

    int mat1[r1][c1];

    printf("Enter rows & columns of the 2st matrix: ");
    scanf("%d%d", &r2, &c2);

    int mat2[r2][c2];
    int mul[r1][c2];

    if (c1 != r2) {
        printf("Multiplication can't be done.");
        return 0;
    }

    printf("Enter the 1st matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("Enter the 2nd matrix: \n");
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }
    printf("\n\n");

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            mul[i][j] = 0;
            for (int k = 0; k < r2; k++) {
                mul[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    printf("(multiplication of matrices=)\t\n\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d", mul[i][j]);
            printf("\t");
        }
        printf("\n\n");
    }

    return 0;
}