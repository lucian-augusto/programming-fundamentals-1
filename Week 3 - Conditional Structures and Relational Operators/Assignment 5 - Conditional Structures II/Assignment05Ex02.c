#include <stdio.h>

int main(void) {
  int year;
  printf("Por favor, insira um ano para saber se ele é bissexto ou não: ");
  scanf("%d", &year);

  printf("\n%d ", year);
  if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
    printf("é um ano bissexto");
  } else {
    printf("não é um ano bissexto");
  }

  return 0;
}