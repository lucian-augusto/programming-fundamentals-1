#include <stdio.h>

void questao01(int *a, int *b);
void questao01Test(int *a, int *b);

int main(void) {
    int n1 = 7;
    int n2 = 0;

    questao01Test(&n1, &n2);
    questao01Test(&n1, &n2);
    questao01Test(&n1, &n2);
    questao01Test(&n1, &n2);
    questao01Test(&n1, &n2);
    questao01Test(&n1, &n2);
    questao01Test(&n1, &n2);

    return 0;
}

void questao01(int *a, int *b) {
    (*a)--;
    (*b)++;
}

void questao01Test(int *a, int *b) {
    printf("Antes de invocar a função: A = %d, B = %d\n", *a, *b);
    questao01(a, b);
    printf("Antes de invocar a função: A = %d, B = %d\n", *a, *b);
}
