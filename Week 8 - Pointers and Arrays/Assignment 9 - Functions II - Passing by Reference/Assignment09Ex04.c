#include <stdio.h>

int divide(int *m, int *n, int d);
int mmc (int m, int n);
void captureInput(int *number);
void validateFirstInput(int *number);

// (c)
int main(void) {
    int lcm, num;

    printf("Este é um programa que calcula o mínimo múltiplo comum entre os números fornecidos.\nPor favor, insira o primeiro número: ");
    scanf("%d", &lcm);
    validateFirstInput(&lcm);

    do {
        captureInput(&num);

        if (num > 0) {
            lcm = mmc(lcm, num);
        }

    } while (num != 0);

    printf("O mínimo múltiplo comum entre os valores digitados é: %d", lcm);

    return 0;
}

// (a)
int divide(int *m, int *n, int d) {
    int divides = 0;

    if (*m % d == 0) {
        *m /= d;
        divides = 1;
    }

    if (*n % d == 0) {
        *n /= d;
        divides = 1;
    }

    return divides;
}

// (b)
int mmc (int m, int n) {
    int mmc = 1;
    int currentDivisor = 2;

    while (m != 1 || n != 1) {
        if (divide(&m, &n, currentDivisor)) {
            mmc *= currentDivisor;
        } else {
            currentDivisor++;
        }
    }

    return mmc;
}

void captureInput(int *number) {
    printf("Por favor, insira um número inteiro e positivo. Zero encerra a entrada e calcula o mmc: ");
    scanf("%d", number);

    while (*number < 0) {
        printf("%d é menor que zero. Por favor, tente novamente: ", *number);
        scanf("%d", number);
    }
}

void validateFirstInput(int *number) {
    while (*number <= 0) {
        printf("O valor deve ser positivo. Por favor, tente novamente: ");
        scanf("%d", number);
    }
}
