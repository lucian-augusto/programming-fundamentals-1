#include <stdio.h>

int main(void) {
  float base, height, area, perimeter;
  
  printf("Por favor, entre a base do retângulo: ");
  scanf("%f", &base);

  printf("Por favor, entre a altura do retângulo: ");
  scanf("%f", &height);

  area = base * height;

  perimeter = (2 * base) + (2 * height);

  printf("\nA área do retâgulo é %.3f e o perímetro do mesmo retângulo é %.3f.\n", area, perimeter);

  if (area > perimeter) {
    printf("A área do retângulo é maior do que o perímetro.");
  } else {
    printf("O perímetro do retângulo é maior do que a área.");
  } 
  return 0;
}