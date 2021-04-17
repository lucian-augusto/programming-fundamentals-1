#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 5

int isPermutationMatix(int dim, int mat[dim][dim]);
void printIsPermutationMatrix(int isPermutationMatix);
void fillMatrix(int dim, int mat[dim][dim]);
void printMatrix(int dim, int mat[dim][dim]);

int main(void) {
    srand(time(NULL));
    int testMatrix1[DIM][DIM];
    int testMatrix2[DIM][DIM] = {{1, 0, 0, 0, 0}, {0 , 1, 0 , 0 , 0}, {0 , 0, 1 , 0 , 0}, {0 , 0, 0 , 1, 0}, {0 , 0, 0 , 0, 1}};
    int dim = DIM;

    fillMatrix(dim, testMatrix1);

    printf("Matriz 1:\n");
    printMatrix(dim, testMatrix1);
    printIsPermutationMatrix(isPermutationMatix(dim, testMatrix1));

    printf("\nMatriz 2:\n");
    printMatrix(dim, testMatrix2);
    printIsPermutationMatrix(isPermutationMatix(dim, testMatrix2));

    return 0;
}

int isPermutationMatix(int dim, int mat[dim][dim]) {
    int lineElementSum;
    int columnElementSum;
    int i, j;

    for (i = 0; i < dim; i++) {
        lineElementSum = 0;
        columnElementSum = 0;
        
        for (j = 0; j < dim; j++) {
            lineElementSum += mat[i][j];
            columnElementSum += mat[j][i];
        }

        if (lineElementSum != 1 || columnElementSum != 1) {
            return 0;
        }
    }

    return 1;
}

void printIsPermutationMatrix(int isPermutationMatix) {
    printf("A matriz ");
    if (!isPermutationMatix) {
        printf("não ");
    }
    printf("é uma matriz de permutação.");
}

void fillMatrix(int dim, int mat[dim][dim]) {
    int i, j;

    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {
            mat[i][j] = rand() % 2;
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
