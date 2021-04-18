#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 7

void multiplyMatrices(int dim, int m1[dim][dim], int m2[dim][dim], int result[dim][dim]);
int calculateCurrentElement(int currentPosX, int currentPosY, int dim, int m1[dim][dim], int m2[dim][dim]);
void calculateMatrixToThePower(int dim, int m[dim][dim], int power, int result[dim][dim]);
void copyMatrix(int dim, int m[dim][dim], int copy[dim][dim]);
void capturePowerInput(int *power);
void fillMatrix(int dim, int mat[dim][dim]);
void printMatrix(int dim, int mat[dim][dim]);

int main(void) {
    srand(time(NULL));
    int matrix1[DIM][DIM];
    int matrix2[DIM][DIM];
    int resultMatrix[DIM][DIM];
    int power;
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

    multiplyMatrices(dim, matrix1, matrix1, resultMatrix);
    printf("Matriz C = A^2\n");
    printMatrix(dim, resultMatrix);

    capturePowerInput(&power);
    calculateMatrixToThePower(dim, matrix1, power, resultMatrix);
    printf("Matriz C = A^%d\n", power);
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

void calculateMatrixToThePower(int dim, int m[dim][dim], int power, int result[dim][dim]) {
    int intermediateResult[dim][dim];

    copyMatrix(dim, m, intermediateResult);

    power--;
    while (power > 0) {
        multiplyMatrices(dim, intermediateResult, m, result);
        power--;
        copyMatrix(dim, result, intermediateResult);
    }
}

void copyMatrix(int dim, int m[dim][dim], int copy[dim][dim]) {
    int i, j;
    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {
            copy[i][j] = m[i][j];
        }
     }
}

void capturePowerInput(int *power) {
    printf("Por favor, insira a expoente para elevar a matriz A: ");
    scanf("%d", power);

    while (*power < 1) {
        printf("valor inválido. O expoente deve ser maior do que 0. Tente novamente: ");
        scanf("%d", power);
    }
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
