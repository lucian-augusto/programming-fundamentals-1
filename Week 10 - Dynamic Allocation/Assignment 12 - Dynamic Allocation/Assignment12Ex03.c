#include <stdio.h>
#include <stdlib.h>

int calculateRepetitionAmount(int *a, int aLength);
int captureArrayLength();
int checkAllocatedArray(int *a);
int* createArray(int tam);
void fillArray(int size, int *a);
int filterArray(int *a, int aLength, int **result);
void printArray(int size, int *a);

int main(void) {
    int length;
    int *array;
    int *filteredArray;
    int newLength;

    length = captureArrayLength();
    array = createArray(length);

    printf("Vetor Original:\n");
    printArray(length, array);

    newLength = filterArray(array, length, &filteredArray);

    printf("O tamanho do vetor filtrado é: %d\nO vetor filtrado é:\n", newLength);

    printArray(newLength, filteredArray);

    free(array);
    free(filteredArray);
    
    return 0;
}

int filterArray(int *a, int aLength, int **result) {
    int resultLength;

    resultLength = aLength - calculateRepetitionAmount(a, aLength);

    *result = (int*) malloc(resultLength * sizeof(int));

    if (checkAllocatedArray(*result)) {
        int resultIndex = 0;
        int isPresent = 0;
        (*result)[resultIndex] = a[0];
        resultIndex++;
        int i, j;
        for (i = 1; i < aLength; i++) {
            isPresent = 0;
            for (j = 0; j < resultIndex; j++) {
                if (a[i] == (*result)[j]) {
                    isPresent = 1;
                }
            }
            if (!isPresent) {
                (*result)[resultIndex] = a[i];
                resultIndex++;
            }
        }
    }

    return resultLength;
}

int calculateRepetitionAmount(int *a, int aLength) {
    int repetitionAmount = 0;
    int i, j;
    
    for (i = 1; i < aLength; i++) {
        for (j = 0; j < i; j++) {
            if (a[i] == a[j]) {
                repetitionAmount++;
                break;
            }
        }
    }
    return repetitionAmount;
}

int* createArray(int tam) {
    int *array;

    array = (int*) malloc(tam * sizeof(int));

    if (checkAllocatedArray(array)) {
        fillArray(tam, array);
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

void fillArray(int size, int *a) {
    int i;

    for (i = 0; i < size; i++) {
        printf("Por favor insira o termo %d: ", i+1);
        scanf("%d", &a[i]);
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
