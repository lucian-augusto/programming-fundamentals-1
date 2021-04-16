#include <stdio.h>

#define DIM 7

void generatePascalTriangle(int dim, int mat[dim][dim]);
void printPascalTriangle(int dim, int mat[dim][dim]);
int isTriangleThreshold(int x, int y);

int main(void) {
    int matrix[DIM][DIM];
    int triangleDimension = DIM;

    generatePascalTriangle(triangleDimension, matrix);

    printPascalTriangle(triangleDimension, matrix);

    return 0;
}

void generatePascalTriangle(int dim, int mat[dim][dim]) {
    int i, j;

    for (i = 0; i < dim; i++) {
        for (j = 0; j <= i; j++) {
            if (isTriangleThreshold(i, j)) {
                mat[i][j] = 1;
            } else {
                mat[i][j] = mat[i-1][j-1] + mat[i-1][j];
            }
        }
    }
}

void printPascalTriangle(int dim, int mat[dim][dim]) {
    int i, j;

    for (i = 0; i < dim; i++) {
        for (j = 0; j <= i; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int isTriangleThreshold(int x, int y) {
    if (x == y || x == 0 || y == 0) {
        return 1;
    }
    return 0;
}
