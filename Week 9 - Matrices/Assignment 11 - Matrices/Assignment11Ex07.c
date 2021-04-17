#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 10

int menu();
void fillMatrix(int dim, int mat[dim][dim]);
void printCreatedMatrices(int areEmpty, int dim, int m1[dim][dim], int m2[dim][dim]);
void sumMatricesAndPrintResult(int areEmpty, int dim, int m1[dim][dim], int m2[dim][dim], int result[dim][dim]);
void subtractMatricesAndPrintResult(int areEmpty, int dim, int m1[dim][dim], int m2[dim][dim], int result[dim][dim]);
void multiplyByConstAndPrintResult(int areEmpty, int dim, int m[dim][dim], int result[dim][dim]);
void printEmptyMatricesError();
void printMatrix(int dim, int mat[dim][dim]);

int main(void) {
    srand(time(NULL));
    int matrix1[DIM][DIM];
    int matrix2[DIM][DIM];
    int resultMatrix[DIM][DIM];
    int areMatricesEmpty = 1;
    int dim = DIM;
    int option = 0;

    while (option != 9) {
        option = menu();

        switch (option) {
            case 0:
                fillMatrix(dim, matrix1);
                fillMatrix(dim, matrix2);
                areMatricesEmpty = 0;
                printf("Matrizes criadas.\n");
                break;

            case 1:
                printCreatedMatrices(areMatricesEmpty, dim, matrix1, matrix2);
                break;

            case 2:
                sumMatricesAndPrintResult(areMatricesEmpty, dim, matrix1, matrix2, resultMatrix);
                break;

            case 3:
                subtractMatricesAndPrintResult(areMatricesEmpty, dim, matrix1, matrix2, resultMatrix);
                break;

            case 4:
                multiplyByConstAndPrintResult(areMatricesEmpty, dim, matrix1, resultMatrix);
                break;
                
            default:
                break;
        }
    }

    return 0;
}

int menu() {
    int option;
    printf("Por favor, escolha das seguintes opções:\n(0) - Criar Matrizes;\n(1) - Imprimir Matrizes Criadas;\n(2) - Somar Matrizes (e imprimir o resultado);\n");
    printf("(3) - Subtrair Matrizes (e imprimir o resultado);\n(4) - Multiplicar Primeira Matriz por uma constante (e imprimir o resultado);\n");
    printf("(9) - Para sair.\nDigite sua opção: ");
    scanf("%d", &option);

    while (option < 0 || (option > 4 && option != 9)) {
        printf("Opção Inválida! Por favor, tente novamente: ");
        scanf("%d", &option);
    }

    return option;
}

void fillMatrix(int dim, int mat[dim][dim]) {
    int i, j;

    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {
            mat[i][j] = rand() % 101;
        }
    }
}

void printCreatedMatrices(int areEmpty, int dim, int m1[dim][dim], int m2[dim][dim]) {
    if (areEmpty) {
        printEmptyMatricesError();
    } else {
        printf("Matriz 1:\n");
        printMatrix(dim, m1);
        printf("\nMatriz 2:\n");
        printMatrix(dim, m2);
    }
}

void sumMatricesAndPrintResult(int areEmpty, int dim, int m1[dim][dim], int m2[dim][dim], int result[dim][dim]) {
    if (areEmpty) {
        printEmptyMatricesError();
    } else {
        int i, j;

        for (i = 0; i < dim; i++) {
            for (j = 0; j < dim; j++) {
                result[i][j] = m1[i][j] + m2[i][j];
            }
        }
        printMatrix(dim, result);
        printf("\n");
    }
}

void subtractMatricesAndPrintResult(int areEmpty, int dim, int m1[dim][dim], int m2[dim][dim], int result[dim][dim]) {
    if (areEmpty) {
        printEmptyMatricesError();
    } else {
        int i, j;

        for (i = 0; i < dim; i++) {
            for (j = 0; j < dim; j++) {
                result[i][j] = m1[i][j] - m2[i][j];
            }
        }
        printMatrix(dim, result);
        printf("\n");
    }
}

void multiplyByConstAndPrintResult(int areEmpty, int dim, int m[dim][dim], int result[dim][dim]) {
    if (areEmpty) {
        printEmptyMatricesError();
    } else {
        int i, j, constant;

        printf("Digite a constante para multiplicar pela matriz: ");
        scanf("%d", &constant);

        for (i = 0; i < dim; i++) {
            for (j = 0; j < dim; j++) {
                result[i][j] = constant * m[i][j];
            }
        }
        printMatrix(dim, result);
        printf("\n");
    }
}

void printEmptyMatricesError() {
    printf("As matrizes não foram preenchidas ainda. Por favor as preencha antes de realizar qualquer operação.\n");
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
