#include <stdio.h>

int main(void) {
  int amount, number, previousNumber, i;
  int segmentCounter = 1;

  printf("Por favor, insira o número (inteiro) de elementos a serem avaliados: ");
  scanf("%d", &amount);

  printf("Insira a sequência de %d elementos:\n", amount);
  for (i = 0; i < amount; i++) {
    scanf("%d", &number);

    if (number != previousNumber && i != 0) {
      segmentCounter++;
    }
    previousNumber = number;
  }

  printf("Quantidade de segmentos = %d\n", segmentCounter);
  return 0;
}