#include <stdio.h>
#include <math.h>

int main(void) {
  int number, unit, ten, hundred;
  printf("Por favor, insira um número (inteiro) entre 100 e 999: ");
  scanf("%d", &number);

  if (number < 100 || number > 999) {
    printf("%d está fora do intervalo permitido", number);
    return 0;
  }

  hundred = number / 100;
  ten = (number / 10) % 10;
  unit = number % 10;

  printf("%d ", number);

  if ((pow(hundred, 3) + pow(ten, 3) + pow(unit, 3)) != number) {
    printf("não ");
  }
  printf("é um número de Angstron");

  return 0;
}