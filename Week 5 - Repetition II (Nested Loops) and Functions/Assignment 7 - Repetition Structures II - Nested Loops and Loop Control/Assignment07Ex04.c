#include <stdio.h>

int main(void) {
  int number, i, j;

  printf("Por favor, insira um número inteiro e maior que zero: ");
  scanf("%d", &number);

  if (number < 1) {
    printf("%d não é maior que zero", number);
    return 0;
  }

  for (i = 1; i <= number; i++) {
    
    printf("%d ", i);

    for (j = 1; j <= i; j++) {
      printf("%d ", i * j);
    }
    printf("\n");
  }
  return 0;
}