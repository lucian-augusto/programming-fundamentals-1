#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_LENGTH 7

void preencheVetor(int v[], int n);
void printArray(int a[]);
void printArrayReversed(int a[]);
void inputCapture(int *input);

int main(void) {
    srand(time(NULL));
    int array[ARRAY_LENGTH];
    int elementThreshold;

    inputCapture(&elementThreshold);

    preencheVetor(array, elementThreshold);

    printf("Vetor: ");
    printArray(array);

    printf("\nVetor Invertido: ");
    printArrayReversed(array);
    
    return 0;
}

void preencheVetor(int v[], int n) {
    int i;

    for (i = 0; i < ARRAY_LENGTH; i++) {
        v[i] = (rand() % n) + 1;
    }
}

void printArray(int a[]) {
    int i;

    printf("[");
    for (i = 0; i < ARRAY_LENGTH; i++) {
        printf("%d ", a[i]);
    }
    printf("]");
}

void printArrayReversed(int a[]) {
    int i;

    printf("[ ");
    for (i = ARRAY_LENGTH - 1; i >= 0 ; i--) {
        printf("%d ", a[i]);
    }
    printf("]");
}

void inputCapture(int *input) {
    printf("Por favor, insira o valor máximo para os elementos do vetor: ");
    scanf("%d", input);
    while (*input <= 0) {
        printf("O valor máximo não pode ser menor ou igual a zero! Por favor, tente outro valor: ");
        scanf("%d", input);
    }
}
