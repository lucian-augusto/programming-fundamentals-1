#include <stdio.h>
#include <math.h>

int main(void) {
  float a, b, c;
  printf("Por favor, insira os lados de um triângulo (separados por espaço): ");
  scanf("%f %f %f", &a, &b, &c);

  if ((a + b <= c) || (a + c <= b) || (b + c <= a)) {
    printf("As medidas inseridas não formam um triângulo, pois não obedecem à desigualdade triangular");
    return 0;
  }

  printf("Os lados informados formam um triângulo ");
  if (a == b && b == c) {
    printf("equilátero.");
  } else if (a != b && b != c && c != a) {
    printf("escaleno.");
  } else {
    printf("isósceles.");
  }
  return 0;
}