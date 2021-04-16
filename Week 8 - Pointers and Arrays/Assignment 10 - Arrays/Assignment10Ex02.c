#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_LENGTH 7

void fillArray(int array[], int *length);
void printArray(int array[], int *length);
void captureIndexInput(int *input, int *length);
void removeArrayElementByIndex(int array[], int *length, int *index);

int main(void) {
    int length = ARRAY_LENGTH;
    int array[ARRAY_LENGTH];
    int input = -1;

    fillArray(array, &length);

    do {
        printArray(array, &length);

        captureIndexInput(&input, &length);

        removeArrayElementByIndex(array, &length, &input);
    } while (input != -1 && length > 0);

    printf("Vetor Final:\n");
    printArray(array, &length);

    return 0;
}

void fillArray(int array[], int *length) {
    int i;
    srand(time(NULL));

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

void captureIndexInput(int *input, int *length) {
    printf("Por favor, insira o índice do elemento que você deseja excluir (ou \"-1\" para sair): ");
    scanf("%d", input);
    while (*input < -1 || *input >= *length) {
        printf("Índice fora dos limites. Por favor, tente novamente: ");
        scanf("%d", input);
    }
}

void removeArrayElementByIndex(int array[], int *length, int *index) {
    int i;
    if (*index >= 0 && *index < *length) {
        for (i = *index; i < *length; i++) {
            array[i] = array[i + 1];
        }
        *length -= 1;
    }
}
