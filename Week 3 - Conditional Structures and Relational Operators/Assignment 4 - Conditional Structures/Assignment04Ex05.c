#include <stdio.h>
#include <math.h>

int main(void) {
  float a, b, c, delta, root1, root2;

  printf("Por favor, insira os coeficientes de uma equação do segundo grau no formato ax^2 + bx + c = 0\na: ");
  scanf("%f", &a);

  printf("b: ");
  scanf("%f", &b);

  printf("c: ");
  scanf("%f", &c);

  if (a == 0) {
    printf("\nNuma equação do segundo grau no formato ax^2 + bx + c = 0, 'a' não pode ser zero!");
    return 0;
  }

  delta = pow(b,2) - (4 * a * c);

  if (delta > 0) {
    root1 = (-b + sqrt(delta)) / (2 * a);
    root2 = (-b - sqrt(delta)) / (2 * a);
    printf("\nA equação do segundo grau %.3fx^2 + %.3fx + %.3f = c possui duas raízes distintas:\nx' = %.3f\nx\" = %.3f", a, b, c, root1, root2);
  } else if (delta == 0) {
    root1 = -b  / (2 * a);
    printf("\nA equação do segundo grau %.3fx^2 + %.3fx + %.3f = c possui duas raízes iguais:\nx' = x\" = %.3f", a, b, c, root1);
  }

  return 0;
}