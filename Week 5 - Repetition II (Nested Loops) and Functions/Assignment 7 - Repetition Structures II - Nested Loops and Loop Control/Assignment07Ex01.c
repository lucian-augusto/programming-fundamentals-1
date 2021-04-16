#include <stdio.h>

int main(void) {
  int num1, num2, i, j;

  printf("Por favor, insira o primeiro número: ");
  scanf("%d", &num1);

  printf("Por favor, insira o segundo número: ");
  scanf("%d", &num2);

  for (i = 1; i <= num1; i++) {
    for (j = 1; j <= num2; j++) {
      printf("%d  ", i*j);
    }
    printf("\n");
  }
  return 0;
}