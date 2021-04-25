#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** allocateMatrix(int lines, int columns);
void captureColumns(int *dim);
void captureLines(int *dim);
int checkAllocatedArray(int *a);
void fillMatrix(int lines, int columns, int **mat);
void freeMatrix(int **m, int size);
void printMatrix(int lines, int columns, int **mat);
void printTransposeMatrix(int lines, int columns, int **mat);

int main(void) {
    srand(time(NULL));
    int **matrix;
    int lines;
    int columns;

    captureLines(&lines);
    captureColumns(&columns);

    matrix = allocateMatrix(lines, columns);

    fillMatrix(lines, columns, matrix);

    printf("Matriz: \n");
    printMatrix(lines, columns, matrix);

    printf("\nMatriz Transposta: \n");
    printTransposeMatrix(lines, columns, matrix);

    return 0;
}

int** allocateMatrix(int lines, int columns) {
    int **m;

    m = (int**) malloc(lines * sizeof(int*));

    int i;
    for (i = 0; i < lines; i++) {
        m[i] = (int*) malloc(columns * sizeof(int));
        if (!checkAllocatedArray(m[i])) {
            freeMatrix(m, lines);
            return NULL;
        }
    }
    return m;
}

void captureLines(int *dim) {
    printf("Por favor, insira o número de linhas da matriz: ");
    scanf("%d", dim);

    while (*dim < 1) {
        printf("A Matriz precisa ter no mínimo 2x2. Por favor, tente novamente: ");
        scanf("%d", dim);
    }
}

void captureColumns(int *dim) {
    printf("Por favor, insira o número de colunas da matriz: ");
    scanf("%d", dim);

    while (*dim < 1) {
        printf("A Matriz precisa ter no mínimo 2x2. Por favor, tente novamente: ");
        scanf("%d", dim);
    }
}

int checkAllocatedArray(int *a) {
    if (a == NULL) {
        printf("Erro ao alocar memória para o vetor.");
        return 0;
    }
    return 1;
}

void fillMatrix(int lines, int columns, int **mat) {
    int i, j;

    for (i = 0; i < lines; i++) {
        for (j = 0; j < columns; j++) {
            mat[i][j] = rand() % 101;
        }
    }
}

void freeMatrix(int **m, int size) {
    int i;
    for (i = 0; i < size; i++) {
        free(m[i]);
    }
    free(m);
}

void printMatrix(int lines, int columns, int **mat) {
    int i, j;

    for (i = 0; i < lines; i++) {
        for (j = 0; j < columns; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void printTransposeMatrix(int lines, int columns, int **mat) {
    int i, j;

    for (i = 0; i < columns; i++) {
        for (j = 0; j < lines; j++) {
            printf("%d ", mat[j][i]);
        }
        printf("\n");
    }
}
