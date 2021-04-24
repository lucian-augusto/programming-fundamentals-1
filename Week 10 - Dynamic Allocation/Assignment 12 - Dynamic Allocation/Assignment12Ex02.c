#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIMIT 10

int captureArrayLength();
int checkAllocatedArray(int *a);
int* createArray(int tam, int lim);
void fillArray(int size, int *a, int limit);
int* multiplyArrays(int *a1, int a1Size, int *a2, int a2Size);
void printArray(int size, int *a);

int main(void) {
    srand(time(NULL));
    int *array1, *array2, *result;
    int size1, size2;

    size1 = captureArrayLength();

    printf("Vetor 1:\n");
    array1 = createArray(size1, LIMIT);
    printArray(size1, array1);
  
    size2 = captureArrayLength();
    
    printf("Vetor 2:\n");
    array2 = createArray(size2, LIMIT);
    printArray(size2, array2);

    printf("Resultado da multiplicação termo a termo entre os vetores:\n");
    result = multiplyArrays(array1, size1, array2, size2);
    printArray(size1 * size2, result);

    free(array1);
    free(array2);
    free(result);
    
    return 0;
}

int* multiplyArrays(int *a1, int a1Size, int *a2, int a2Size) {
    int *result;
    int i, j;
    int resultIndex = 0;

    result = (int*) malloc(a1Size * a2Size * sizeof(int));

    if (checkAllocatedArray(result)) {
        for (i = 0; i < a1Size; i++) {
            for(j = 0; j < a2Size; j++) {
                result[resultIndex] = a1[i] * a2[j];
                resultIndex++;
            }
        }
    }
    return result;
}

int* createArray(int tam, int lim) {
    int *array;

    array = (int*) malloc(tam * sizeof(int));

    if (checkAllocatedArray(array)) {
        fillArray(tam, array, lim);
    }

    return array;
}

int checkAllocatedArray(int *a) {
    if (a == NULL) {
        printf("Erro ao alocar memória para o vetor.");
        return 0;
    }
    return 1;
}

void fillArray(int size, int *a, int limit) {
    int i;

    for (i = 0; i < size; i++) {
        a[i] = rand() % (limit + 1);
    }
}

void printArray(int size, int *a) {
    int i;

    if (a == NULL) {
        printf("NULL array.");
    } else {
        for (i = 0; i < size; i++) {
            printf("%d\t", a[i]);
        }
    printf("\n");
    }
}

int captureArrayLength() {
    int length;

    printf("Por favor, insira o tamanho do vetor: ");
    scanf("%d", &length);

    while (length < 2) {
        printf("Um vetor precisa ter no mínimo 2 elementos. Por favor, tente novamente: ");
        scanf("%d", &length);
    }

    return length;
}
