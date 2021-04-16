#include <stdio.h>

int main(void) {
  float a, g, ra, rg, ratioA, ratioG; 

  printf("Por favor, insira os precos do álcool e da gasolina (R$/L) e o rendimento do(s) carro(s) com álcool e gasolina, em km/L (na ordem acima e separados por espaço): ");
  scanf("%f %f %f %f", &a, &g, &ra, &rg);

  ratioA = ra / a;
  ratioG = rg / g;

  printf("\n");
  if (ratioA > ratioG) {
    printf("A");
  } else if (ratioA < ratioG) {
    printf("G");
  } else {
    printf("Indiferente");
  }
  return 0;
}