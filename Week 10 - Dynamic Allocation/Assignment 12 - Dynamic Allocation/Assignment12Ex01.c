#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int * criaVetor(int tam, int lim);
int * expandeVetor(int *v, int tam, int n, int lim);
void criaVetorPorReferencia(int **v, int tam, int lim);
void fillArrayWithPositiveAndNegativeNumbers(int size, int a[], int limit);
void fillArray(int size, int a[], int limit);
void printArray(int size, int a[]);
int captureArrayLength();
int captureNumberLimit();
int captureResize();

int main(void) {
    srand(time(NULL));
    int *array1, *array2;
    int size;
    int expansionSize;
    int limit;

    size = captureArrayLength();
    limit = captureNumberLimit();

    printf("Vetor 1:\n");
    array1 = criaVetor(size, limit);
    printArray(size, array1);

    expansionSize= captureResize();

    printf("Vetor 1 (expandido):\n");
    array1 = expandeVetor(array1, size, expansionSize, limit);
    printArray(size+expansionSize, array1);

    printf("Vetor 2 (gerado usando passagem por referência - além de alocação dinâmica):\n");
    criaVetorPorReferencia(&array2, size, limit);
    printArray(size, array2);

    return 0;
}

// (a)
int * criaVetor(int tam, int lim) {
    int *array;

    array = (int*) malloc(tam * sizeof(int));

    fillArray(tam, array, lim);

    return array;
}

// (b)
int * expandeVetor(int *v, int tam, int n, int lim) {
    int *a;

    a = (int*) realloc(v, (tam + n) * sizeof(int));

    fillArray(n, a+tam, lim);

    return a;
}

// Challenge
void criaVetorPorReferencia(int **v, int tam, int lim) {
    *v = (int*) malloc(tam * sizeof(int));

    fillArrayWithPositiveAndNegativeNumbers(tam, *v, lim);
}

void fillArrayWithPositiveAndNegativeNumbers(int size, int a[], int limit) {
    int i;

    for (i = 0; i < size; i++) {
        a[i] = (rand() % (2 * (limit))) - limit;
    }
}

void fillArray(int size, int a[], int limit) {
    int i;

    for (i = 0; i < size; i++) {
        a[i] = rand() % (limit + 1);
    }
}

void printArray(int size, int a[]) {
    int i;

    for (i = 0; i < size; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

int captureArrayLength() {
    int length;

    printf("Por favor, insira o tamanho dos vetores: ");
    scanf("%d", &length);

    while (length < 2) {
        printf("Um vetor precisa ter no mínimo 2 elementos. Por favor, tente novamente: ");
        scanf("%d", &length);
    }

    return length;
}

int captureNumberLimit() {
    int limit;

    printf("Por favor, insira o número limite (máximo) parapreencher os vetores: ");
    scanf("%d", &limit);

    while (limit < 1) {
        printf("É necessário um valor maior que 0. Por favor, tente novamente: ");
        scanf("%d", &limit);
    }

    return limit;
}

int captureResize() {
    int resize;

    printf("Por favor, insira o quando deseja expandir o vetor (em unidades): ");
    scanf("%d", &resize);

    return resize;
}
