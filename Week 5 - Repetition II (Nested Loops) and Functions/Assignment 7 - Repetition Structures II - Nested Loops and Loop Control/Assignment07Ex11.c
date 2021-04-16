#include <stdio.h>

int main(void) {
  int amount, initialValue, i, j, isPrime;

  printf("Por favor, insira o número de números primos que você deseja imprimir: ");
  scanf("%d", &amount);

  printf("Insira agora, o valor inicial: ");
  scanf("%d", &initialValue);

  if (amount < 0 || initialValue < 0) {
    printf("Nenhum dos valores podem ser negativos");
    return 0;
  }

  if (initialValue < 2) {
    initialValue = 2;
  }
  
  i = 0;
  while (i < amount) {
    isPrime = 1;
    for (j = 2; j < initialValue; j++) {
      if (initialValue % j == 0) {
        isPrime = 0;
        break;
      }
    }
    if (isPrime) {
        printf("%d ", initialValue);
        i++;  
      }
    initialValue++;
  }
  

  return 0;
}