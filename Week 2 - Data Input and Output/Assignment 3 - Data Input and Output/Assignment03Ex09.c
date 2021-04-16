#include <stdio.h>

int main(void) {
  float base, height, perimeter;

  printf("Por favor, insira um valor para a base do retângulo: ");
  scanf("%f", &base);

  printf("Por favor, insira um valor para a altura do retângulo: ");
  scanf("%f", &height);

  perimeter = (2 * base) + (2 * height);

  printf("O perímetro do retângulo é: %.2f", perimeter);
  return 0;
}