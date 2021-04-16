#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_LENGTH 7

void intercalaVetores(int v1[], int v2[], int v3[], int n);
void preencheVetor(int v[], int n);
void printArray(int a[], int length);
void inputCapture(int *input);

int main(void) {
    srand(time(NULL));
    int length = ARRAY_LENGTH;
    int array1[length];
    int array2[length];
    int intercalatedArray[2*length];
    
    int elementThreshold;

    inputCapture(&elementThreshold);

    preencheVetor(array1, elementThreshold);

    printf("Vetor 1: ");
    printArray(array1, length);

    preencheVetor(array2, elementThreshold);

    printf("\nVetor 2: ");
    printArray(array2, length);

    intercalaVetores(array1, array2, intercalatedArray, length);

    printf("\nVetor Intercalado: ");
    printArray(intercalatedArray, 2*length);

    return 0;
}

void intercalaVetores(int v1[], int v2[], int v3[], int n) {
    int i;
    int v1Index = 0;
    int v2Index = 0;

    for (i = 0; i < 2 * n; i++) {
        if (i % 2 == 0) {
            v3[i] = v1[v1Index];
            v1Index++;
        } else {
            v3[i] = v2[v2Index];
            v2Index++;
        }
    }
}

void preencheVetor(int v[], int n) {
    int i;

    for (i = 0; i < ARRAY_LENGTH; i++) {
        v[i] = (rand() % n) + 1;
    }
}

void printArray(int a[], int length) {
    int i;

    printf("[");
    for (i = 0; i < length; i++) {
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
