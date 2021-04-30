#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SENTENCE_MAX_SIZE 100

typedef struct vowelCounter {
    int a;
    int e;
    int i;
    int o;
    int u;
} VowelCounter;

void* allocateArray(int size);
char* captureSentence(int maxSize);
void printNumberOfVowels(VowelCounter *c);
void vowelCounter(char *sentence, VowelCounter *c);


int main(void) {
    char *sentence;
    VowelCounter counter;

    sentence = captureSentence(SENTENCE_MAX_SIZE);

    vowelCounter(sentence, &counter);

    printf("A frase: \"%s\" possui:\n", sentence);

    printNumberOfVowels(&counter);

    free(sentence);

    return 0;
}

void* allocateArray(int size) {
    void *array;

    array = malloc(size);

    if (array == NULL) {
        printf("Erro ao alocar vetor");
    }

    return array;
}

char* captureSentence(int maxSize) {
    char *sentence;

    sentence = (char*) allocateArray(maxSize * sizeof(char));

    printf("Por favor, insira a sua frase (Máximo de %d caracteres):\n", maxSize);

    if (fgets(sentence, maxSize, stdin) == NULL) {
        printf("Erro ao escrever frase");
        return NULL;
    }

    return sentence;
}

void printNumberOfVowels(VowelCounter *c) {
    int i;

    printf("a : ");
    for (i = 0; i < c->a; i++) {
        printf("*");
    }
    printf(" (%d)\ne : ", c->a);
    for (i = 0; i < c->e; i++) {
        printf("*");
    }
    printf(" (%d)\ni : ", c->e);
    for (i = 0; i < c->i; i++) {
        printf("*");
    }
    printf(" (%d)\no : ", c->i);
    for (i = 0; i < c->o; i++) {
        printf("*");
    }
    printf(" (%d)\nu : ", c->o);
    for (i = 0; i < c->u; i++) {
        printf("*");
    }
    printf(" (%d)\n", c->u);
}

void vowelCounter(char *sentence, VowelCounter *c) {
    int i;

    c->a = 0;
    c->e = 0;
    c->i = 0;
    c->o = 0;
    c->u = 0;

    for (i = 0; sentence[i] != '\0'; i++) {
        switch (tolower(sentence[i])) {
            case 'a':
                c->a++;
                break;

            case 'e':
                c->e++;
                break;

            case 'i':
                c->i++;
                break;

            case 'o':
               c->o++;
                break;

            case 'u':
                c->u++;
                break;

            default:
                break;
        }

    }
}
