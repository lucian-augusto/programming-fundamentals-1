#include <stdio.h>

int main(void) {
  int distance;
  float fuel, avgConsumption;

  printf("Por favor, insira a distância percorrida (número inteiro): ");
  scanf("%d", &distance);

  printf("Por favor, insira a quantidade de conbustível utilizada (número real): ");
  scanf("%f", &fuel);

  avgConsumption = distance / fuel;

  printf("O consumo médio foi de %.3f km/l", avgConsumption);
  return 0;
}