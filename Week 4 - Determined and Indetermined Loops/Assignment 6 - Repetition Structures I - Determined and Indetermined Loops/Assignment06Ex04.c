#include <stdio.h>

int main(void) {
  int numberOfLoops, i;
  float num1, num2, num3, avg;

  printf("Por favor insira a quantidade de médias ponderadas (pesos 2, 3 e 5) você deseja calcular: ");
  scanf("%d", &numberOfLoops);

  for (i = 0; i < numberOfLoops; i++) {
    printf("\nPor favor insira os três valores para calcular a média: ");
    scanf("%f %f %f", &num1, &num2, &num3);

    avg = ((num1 * 2) + (num2 * 3) + (num3 * 5)) / (2 + 3 + 5);
    printf("\nMédia = %.1f", avg);
  }
  return 0;
}