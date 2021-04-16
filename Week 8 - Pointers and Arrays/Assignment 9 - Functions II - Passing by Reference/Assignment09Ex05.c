#include <stdio.h>

void removeExtremos(int *n, int *pri, int *ult);
int isPalindrome(int number);
void verifyInput(int *number);

int main(void) {
    int number;

    printf("Por favor, insira um número inteiro positivo: ");
    scanf("%d", &number);
    verifyInput(&number);

    printf("%d ", number);
    if (!isPalindrome(number)) {
        printf("não ");
    }
    printf("é um palíndromo");
    return 0;
}

int isPalindrome(int number) {
    int firstDigit, lastDigit;
    int isPalindrome = 1;

    while (number > 0) {
        removeExtremos(&number, &firstDigit, &lastDigit);

        if (firstDigit != lastDigit) {
            isPalindrome = 0;
            break;
        }
    }

    return isPalindrome;
}

void verifyInput(int *number) {
    while (*number <= 0) {
        printf("%d não é positivo. Por favor, tente novamente: ", *number);
        scanf("%d", number);
    }
}

void removeExtremos(int *n, int *pri, int *ult) {
    int tn,pot = 1;
    tn = *n;
    while(tn >= 10){
        tn = tn/10;
        pot *= 10;
    }
    *pri = *n / pot;
    *ult = *n % 10;
    *n = *n % pot;
    *n = *n / 10;
}
