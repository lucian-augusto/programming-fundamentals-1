#include <stdio.h>

int main(void) {
  int number, functionCalc, i, j;
  
  printf("Insira o intervalo (usando um número inteiro e maior que zero) para plotar a função f(x) = x^2 + x + 1: ");
  scanf("%d", &number);

  for (i = -number; i <= number; i++) {
    functionCalc = i * i + i + 1;

    printf("%d: ", i);
    for (j = 0; j < functionCalc; j++) {
      printf(".");
    }
    printf("*\n");
  }
  return 0;
}