#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 3

int isMagicSquare(int dim, int mat[dim][dim]);
void printIsMagicSquare(int isMagicSquare);
void fillMatrix(int dim, int mat[dim][dim]);
void printMatrix(int dim, int mat[dim][dim]);

int main(void) {
    srand(time(NULL));
    int testMatrix1[DIM][DIM];
    int testMatrix2[DIM][DIM] = {{8, 0, 7}, {4, 5, 6}, {3, 10, 2}};
    int dim = DIM;

    fillMatrix(dim, testMatrix1);

    printf("Matriz 1:\n");
    printMatrix(dim, testMatrix1);
    printIsMagicSquare(isMagicSquare(dim, testMatrix1));

    printf("\nMatrix 2:\n");
    printMatrix(dim, testMatrix2);
    printIsMagicSquare(isMagicSquare(dim, testMatrix2));

    return 0;
}

int isMagicSquare(int dim, int mat[dim][dim]) {
    int lineElementSum = 0;
    int columnElementSum = 0;
    int mainDiagonalSum = 0;
    int secondaryDiagonalSum = 0;
    int previousElementSum = 0;
    int isMagicSquare = 1;
    int i, j;

    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {
            lineElementSum += mat[i][j];
            columnElementSum += mat[j][i];
        }

        if ((lineElementSum != previousElementSum && i != 0) || (lineElementSum != columnElementSum)) { // Checks if the sum of the elements in the line is equal to the previous sum (only if not on first line/column)
                                                                                                        // and if the sum of the line elements is equals to the sum of the column elements.
            return 0;
        }
        mainDiagonalSum += mat[i][i];
        secondaryDiagonalSum += mat[i][dim-1-i];
        previousElementSum = lineElementSum;
        lineElementSum = 0;
        columnElementSum = 0;
    }

    if (mainDiagonalSum != secondaryDiagonalSum || mainDiagonalSum != previousElementSum) {
        isMagicSquare = 0;
    }

    return isMagicSquare;
}

void printIsMagicSquare(int isMagicSquare) {
    printf("A matriz ");
    if (!isMagicSquare) {
        printf("não ");
    }
    printf("é um quadrado mágico.");
}

void fillMatrix(int dim, int mat[dim][dim]) {
    int i, j;

    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {
            mat[i][j] = rand() % 101;
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
