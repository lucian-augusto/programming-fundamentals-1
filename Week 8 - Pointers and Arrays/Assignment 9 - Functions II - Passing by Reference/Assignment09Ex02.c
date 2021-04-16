#include <stdio.h>
#include <math.h>

int calculaRaizes(float a, float b, float c, float *x1, float *x2);
void printResult(float *a, float *b, float *c, float *x1, float *x2, int *isComplex);
void captureCoefficients(float *a, float *b, float *c);

int main(void) {
    int isComplex;
    float a, b, c;
    float x1 = 0;
    float x2 = 0;

    captureCoefficients(&a, &b, &c);

    isComplex = calculaRaizes(a, b, c, &x1, &x2);

    printResult(&a, &b, &c, &x1, &x2, &isComplex);

    return 0;
}

int calculaRaizes(float a, float b, float c, float *x1, float *x2) {
    float delta = pow(b, 2) - 4 * a * c;

    if (delta < 0) {
        *x1 = -b / (2 * a);
        *x2 = -b / (2 * a);
        return 1;
    }
    *x1 = (-b + sqrt(delta)) / (2 * a);
    *x2 = (-b - sqrt(delta)) / (2 * a);
    return 0;
}

void printResult(float *a, float *b, float *c, float *x1, float *x2, int *isComplex) {
    printf("As raízes da equação do segundo grau %.2fx^2 + (%.2f)x + (%.2f) são:\n", *a, *b, *c);

    if (*isComplex) {
        float delta = pow(*b, 2) - 4 * *a * *c;
        printf("x1 = %.2f + %.2fi\nx2 = %.2f - %.2fi", *x1, sqrt(-delta) / (2 * *a), *x2, sqrt(-delta) / (2 * *a));
    } else {
        printf("x1 = %.2f\nx2 = %.2f", *x1, *x2);
    }
}

void captureCoefficients(float *a, float *b, float *c) {
    printf("Por favor, insira os coeficientes de uma equação do segundo grau:\na: ");
    scanf("%f", a);
    while (*a == 0) {
        printf("a = 0 não caracteriza uma equação do segundo grau. Tente novamente: ");
        scanf("%f", a);
    }

    printf("b: ");
    scanf("%f", b);

    printf("c: ");
    scanf("%f", c);

}
