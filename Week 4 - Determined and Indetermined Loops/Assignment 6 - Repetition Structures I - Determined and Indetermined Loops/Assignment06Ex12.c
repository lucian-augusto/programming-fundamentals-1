#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n1, n2, mmc, i, biggerNumber;


  printf("Por favor, insira o primeiro número (inteiro) para calcular o MMC: ");
  scanf("%d", &n1);

  printf("Por favor, insira o segundo número (inteiro) para calcular o MMC: ");
  scanf("%d", &n2);

  biggerNumber = (n1 + n2 + abs(n1 - n2)) / 2; // O MMC é sempre >= que MAX(n1, n2)

  mmc = 0;
  i = biggerNumber; // O MMC é sempre >= que MAX(n1, n2)
  while (mmc == 0) {
    if (i % n1 == 0 && i % n2 == 0) {
      mmc = i;
    } else {
      i++;
    }
  }

  printf("\nO Mínimo Múltiplo Comum entre %d e %d é %d", n1, n2, mmc);
  return 0;
}