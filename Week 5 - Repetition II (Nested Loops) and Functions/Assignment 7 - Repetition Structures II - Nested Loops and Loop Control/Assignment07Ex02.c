#include <stdio.h>

int main(void) {
  int number, i, j, firstOdd, lastOdd, oddSum;

  printf("Por favor, insira um número (inteiro) para calcular o cubo de todos os números até o inserido utilizando o método dos ímpares consecutivos: ");
  scanf("%d", &number);

  for (i = 1; i <= number; i++) {
    oddSum = 0;
    firstOdd = i * (i - 1) + 1;
    lastOdd = firstOdd + ((i - 1) * 2);

    printf("%d^3 = ", i);
    for (j = firstOdd; j <= lastOdd; j += 2) {
      if (j == firstOdd) { 
        printf("%d ", j);
      } else {
        printf("+ %d ", j);
      }
      oddSum += j;
    }
    printf("= %d\n", oddSum);
  }
  return 0;
}