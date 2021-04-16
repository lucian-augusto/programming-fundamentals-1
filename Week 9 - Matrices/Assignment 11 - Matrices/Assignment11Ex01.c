#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 5

void fillMatrix(int lines, int columns, int mat[lines][columns]);
void printMatrix(int lines, int columns, int mat[lines][columns]);
void printTransposeMatrix(int lines, int columns, int mat[lines][columns]);

int main(void) {
    srand(time(NULL));
    int matrix[DIM][DIM];
    int lines = DIM;
    int columns = DIM;

    fillMatrix(lines, columns, matrix);

    printf("Matriz: \n");
    printMatrix(lines, columns, matrix);

    printf("\nMatriz Transposta: \n");
    printTransposeMatrix(lines, columns, matrix);

    return 0;
}

void fillMatrix(int lines, int columns, int mat[lines][columns]) {
    int i, j;

    for (i = 0; i < lines; i++) {
        for (j = 0; j < columns; j++) {
            mat[i][j] = rand() % 101;
        }
    }
}

void printMatrix(int lines, int columns, int mat[lines][columns]) {
    int i, j;

    for (i = 0; i < lines; i++) {
        for (j = 0; j < columns; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void printTransposeMatrix(int lines, int columns, int mat[lines][columns]) {
    int i, j;

    for (i = 0; i < lines; i++) {
        for (j = 0; j < columns; j++) {
            printf("%d ", mat[j][i]);
        }
        printf("\n");
    }
}
