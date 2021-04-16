#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_LENGTH 7

void preencheVetor(int v[], int n);
void printArray(int a[]);
void inputCapture(int *input);
float calculateEvenNumbersAverage(int a[], int *length);

int main(void) {
    srand(time(NULL));
    int array[ARRAY_LENGTH];
    int elementThreshold;
    float avg;
    int legnth = ARRAY_LENGTH;

    inputCapture(&elementThreshold);

    preencheVetor(array, elementThreshold);

    printf("Vetor: ");
    printArray(array);

    avg = calculateEvenNumbersAverage(array, &legnth);
    
    if (avg != -1) {
        printf("\nA média dos valores pares do vetor gerado é: %.2f", avg);
    } else {
        printf("\nO vetor não possui elementos pares.");
    }

    return 0;
}

float calculateEvenNumbersAverage(int a[], int *length) {
    int i;
    float avg = 0;
    int evenCounter = 0;

    for (i = 0; i < *length; i++) {
        if (a[i] % 2 == 0) {
            avg += a[i];
            evenCounter++;
        }
    }
    if (evenCounter) {
        return avg / evenCounter;
    }
    return -1;
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

void inputCapture(int *input) {
    printf("Por favor, insira o valor máximo para os elementos do vetor: ");
    scanf("%d", input);
    while (*input <= 0) {
        printf("O valor máximo não pode ser menor ou igual a zero! Por favor, tente outro valor: ");
        scanf("%d", input);
    }
}
