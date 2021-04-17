#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 7

void multiplyMatrices(int dim, int m1[dim][dim], int m2[dim][dim], int result[dim][dim]);
int calculateCurrentElement(int currentPosX, int currentPosY, int dim, int m1[dim][dim], int m2[dim][dim]);
void fillMatrix(int dim, int mat[dim][dim]);
void printMatrix(int dim, int mat[dim][dim]);

int main(void) {
    srand(time(NULL));
    int matrix1[DIM][DIM];
    int matrix2[DIM][DIM];
    int resultMatrix[DIM][DIM];
    int dim = DIM;

    fillMatrix(dim, matrix1);
    printf("Matriz A:\n");
    printMatrix(dim, matrix1);

    fillMatrix(dim, matrix2);
    printf("Matriz A:\n");
    printMatrix(dim, matrix2);

    multiplyMatrices(dim, matrix1, matrix2, resultMatrix);
    printf("Matriz C = A * B\n");
    printMatrix(dim, resultMatrix);

    return 0;
}

void multiplyMatrices(int dim, int m1[dim][dim], int m2[dim][dim], int result[dim][dim]) {
    int i, j;

    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {
            result[i][j] = calculateCurrentElement(i, j, dim, m1, m2);
        }
    }
}

int calculateCurrentElement(int currentPosX, int currentPosY, int dim, int m1[dim][dim], int m2[dim][dim]) {
    int result = 0;
    int i;

    for (i = 0; i < dim; i++) {
        result += (m1[currentPosX][i] * m2[i][currentPosY]);
    }

    return result;
}

void fillMatrix(int dim, int mat[dim][dim]) {
    int i, j;

    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {
            mat[i][j] = rand() % 10; // Limiting random numbers from 0 to 9 to make veirifications easier
        }
    }
}


void printMatrix(int dim, int mat[dim][dim]) {
    int i, j;

    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}
