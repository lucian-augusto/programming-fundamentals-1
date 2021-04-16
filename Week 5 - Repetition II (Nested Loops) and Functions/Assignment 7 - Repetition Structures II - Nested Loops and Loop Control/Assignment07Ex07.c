#include <stdio.h>

int main(void) {
  int number, i, multiplication;
  int isTriangular = 0;

  printf("Por favor, insira um número (inteiro): ");
  scanf("%d", &number);

  i = 1;
  while ((i < number / 2) && !isTriangular) {
    multiplication = i * (i + 1) * (i + 2);
    if (multiplication == number) {
      isTriangular = 1;
    }

    i++;
  }

  if (isTriangular) {
    printf("%d é triangular", number);
  } else {
    printf("%d não é triangular", number);
  }

  return 0;
}