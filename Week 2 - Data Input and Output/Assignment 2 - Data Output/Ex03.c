#include <stdio.h>

int main(void) {
  int number;
  printf("Por favor, insira um número inteiro: ");
  scanf("%d", &number);
  printf("O número formatado é: %.3d", number);
  return 0;
}