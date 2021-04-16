#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define LINES 10
#define COLUMNS 10

void fillMatrix(int lines, int columns, int mat[lines][columns]);
void printMatrix(int lines, int columns, int mat[lines][columns]);
void getMinimax(int lines, int columns, int mat[lines][columns], int *maxValue, int *minimax, int *x, int *y);

int main(void) {
    srand(time(NULL));
    int matrix[LINES][COLUMNS];
    int lines = LINES;
    int columns = COLUMNS;
    int maxValue = INT_MIN;
    int minimax = 0;
    int x = 0;
    int y = 0;

    fillMatrix(lines, columns, matrix);

    printf("Matriz:\n");
    printMatrix(lines, columns, matrix);

    getMinimax(lines, columns, matrix, &maxValue, &minimax, &x, &y);

    printf("O minimax da matriz é %d, encontrado na posição %d, %d (considerando que a indexação começa em zero) e o maior elemento da matriz é %d.", minimax, x, y, maxValue);

    return 0;
}

void getMinimax(int lines, int columns, int mat[lines][columns], int *maxValue, int *minimax, int *x, int *y) {
    int i, j;

    for (i = 0; i < lines; i++) {
        for (j = 0; j < columns; j++) {
            if (mat[i][j] > *maxValue) {
                *maxValue = mat[i][j];
                *x = i;
            }
        }
    }

    *minimax = mat[*x][0];
    for (i = 1; i < columns; i++) {
        if (mat[*x][i] < *minimax) {
            *minimax = mat[*x][i];
            *y = i;
        }
    }
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
