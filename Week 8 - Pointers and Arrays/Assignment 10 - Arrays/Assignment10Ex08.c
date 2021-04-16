#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define ARRAY_LENGTH 7

void preencheVetor(int v[], int n);
void printArray(int a[]);
void inputCapture(int *input);
float calculateEvenNumbersAverage(int a[], int *length, int *max, int *min);

int main(void) {
    srand(time(NULL));
    int array[ARRAY_LENGTH];
    int elementThreshold;
    int minValue = INT_MAX;
    int maxValue = INT_MIN;
    float avg;
    int legnth = ARRAY_LENGTH;

    inputCapture(&elementThreshold);

    preencheVetor(array, elementThreshold);

    printf("Vetor: ");
    printArray(array);

    avg = calculateEvenNumbersAverage(array, &legnth, &maxValue, &minValue);
    
    if (avg != -1) {
        printf("\nA média dos valores pares do vetor gerado é: %.2f", avg);
    } else {
        printf("\nO vetor não possui elementos pares.");
    }

    printf("\nMaior valor presente no vetor: %d", maxValue);
    printf("\nMenor valor presente no vetor: %d", minValue);

    return 0;
}

float calculateEvenNumbersAverage(int a[], int *length, int *max, int *min) {
    int i;
    float avg = 0;
    int evenCounter = 0;

    for (i = 0; i < *length; i++) {
        if (a[i] % 2 == 0) {
            avg += a[i];
            evenCounter++;
        }
        if (a[i] > *max) {
            *max = a[i];
        }

        if (a[i] < *min) {
            *min = a[i];
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
