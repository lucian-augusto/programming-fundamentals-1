#include <stdio.h>
#include <math.h>

int main(void) {
  double radius, volume;
  double PI = 3.14159;

  printf("Por favor, insira o raio da esfera: ");
  scanf("%lf", &radius);

  volume = (4.0 / 3) * PI * pow(radius, 3);

  printf("VOLUME = %.3lf", volume);
  return 0;
}