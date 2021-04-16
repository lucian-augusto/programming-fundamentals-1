#include <stdio.h>

int main(void) {
  int number;
  int num;
  int i;
  int sum = 0;

  printf("Por favor, insira um número (inteiro) para verificar se ele é um número perfeito: ");
  scanf("%d", &number);

  for (i = 1; i < number; i++) {
    if (number % i == 0) {
      sum += i;
    }
  }

  printf("\n%d ", number);
  if (sum != number) {
    printf("não ");
  }
  printf("é um número perfeito");

  return 0;
}