#include <stdio.h>

int main(void) {
  int number, i;

  printf("Por favor, insira um número inteiro: ");
  scanf("%d", &number);

  printf("\nImpriminto todos os números de 1 a 100 que divididos por %d possuem resto igual a 2", number);

  for (i = 1; i <= 100; i++) {
    if (i % number == 2) {
      printf("\n%d", i);
    }
  }
  return 0;
}