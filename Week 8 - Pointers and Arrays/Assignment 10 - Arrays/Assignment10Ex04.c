#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getArrayLength();
void fillArray(int array[], int *length);
void printArray(int array[], int *length);
void arrayCrossSum(int a1[], int a2[], int result[], int *length);

int main(void) {
    srand(time(NULL));
    int length = getArrayLength();
    int array1[length];
    int array2[length];
    int result[length];

    fillArray(array1, &length);
    printf("\nVetor 1 (v1): ");
    printArray(array1, &length);

    fillArray(array2, &length);
    printf("\nVetor 2 (v2): ");
    printArray(array2, &length);

    arrayCrossSum(array1, array2, result, &length);
    printf("\nResultado: ");
    printArray(result, &length);

    return 0;
}

void fillArray(int array[], int *length) {
    int i;

    for (i = 0; i < *length; i++) {
        array[i] = (rand() % 100) + 1;
    }
}

void printArray(int array[], int *length) {
    int i;

    printf("[ ");
    for (i = 0; i < *length; i++) {
        printf("%d ", array[i]);
    }
    printf("]\n");
}

int getArrayLength() {
    int length;
    printf("Por favor, insira o tamanho dos vetores: ");
    scanf("%d", &length);

    while (length < 1) {
        printf("O vetores devem conter mais de 1 elemento. Por favor, tente novamente: ");
        scanf("%d", &length);
    }
    return length;
}

void arrayCrossSum(int a1[], int a2[], int result[], int *length) {
    int i;

    for (i = 0; i < *length; i++) {
        result[i] = a1[i] + a2[*length - 1 - i];
    }
}
