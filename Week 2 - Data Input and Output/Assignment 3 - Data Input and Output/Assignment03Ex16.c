#include <stdio.h>

int main(void) {
  int number, lastDigit;

  printf("Por favor, insira um número inteiro: ");
  scanf("%d", &number);

  lastDigit = number % 10;

  printf("\nO último dígito de %d é: %d", number, lastDigit);
  return 0;
}