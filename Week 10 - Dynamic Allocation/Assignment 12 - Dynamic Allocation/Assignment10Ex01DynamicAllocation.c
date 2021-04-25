#include <stdio.h>
#include <stdlib.h>

void getArrayLength(int *length);
void fillArray(int array[], int arrayLength);
int isPresent(int array[], int currentPosition, int num);
void printArray(int array[], int *arrayLength);

int main(void) {
    int arrayLength;
    getArrayLength(&arrayLength);
    int *array;

    array = (int*) malloc(arrayLength * sizeof(int));
    
    fillArray(array, arrayLength);

    printArray(array, &arrayLength);

    free(array);
    return 0;
}

void getArrayLength(int *length) {
    printf("Por favor, insira o tamanho do vetor: ");
    scanf("%d", length);

    while (*length < 1) {
        printf("O vetor deve conter mais de 1 elemento. Por favor, tente novamente: ");
        scanf("%d", length);
    }
}

void fillArray(int array[], int arrayLength) {
    int i, num;

    i = 0;
    while (i < arrayLength) {
        printf("Insira um número (inteiro) para preencher o vetor: ");
        scanf("%d", &num);

        if (!isPresent(array, i, num)) {
            array[i] = num;
            i++;
        } else {
            printf("O número %d já utilizado. Entrada inválida.\n", num);
        }
    }
}

int isPresent(int array[], int currentPosition, int num) {
    int i;
    int isPresent = 0;

    for (i = 0; i <= currentPosition; i++) {
        if (array[i] == num) {
            isPresent = 1;
            break;
        }
    }

    return isPresent;
}

void printArray(int array[], int *arrayLength) {
    int i;

    printf("[ ");
    for (i = 0; i < *arrayLength; i++) {
        printf("%d ", array[i]);
    }
    printf("]");
}

