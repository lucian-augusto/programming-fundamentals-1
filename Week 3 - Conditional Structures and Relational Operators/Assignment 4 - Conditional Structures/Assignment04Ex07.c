#include <stdio.h>

int main(void) {
  float x, y;

  printf("Por favor, insira as coordenadas de um ponto num plano cartesiano (P = (x, y)): ");
  scanf("%f %f", &x, &y);

  if (x == 0 || y == 0) {
    if (x != 0) {
      printf("Eixo x");
    } else if (y != 0) {
      printf("Eixo y");
    } else {
      printf("Origem");
    }
  } else if (x > 0) {
    if (y > 0) {
      printf("Q1");
    } else {
      printf("Q4");
    }
  } else {
    if (y > 0) {
      printf("Q2");
    } else {
      printf("Q3");
    }
  }
  printf("\n");
  return 0;
}