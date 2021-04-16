#include <stdio.h>

int main(void) {
  int limit, i;
  int num1 = 0;
  int num2 = 1;
  printf("Por favor, insira o número de elementos da série de Fibonacci que você deseja imprimir: ");
  scanf("%d", &limit);

  for (i = 0; i < limit; i++) {
    if (i == 0) {
      printf("%d ", num1);
      continue;
    } else {
      printf("%d ", num2);
    }
    num2 += num1;
    num1 = num2 - num1;

  }
  return 0;
}