#include <stdio.h>

int main(void) {
  int efficiency = 15; // km/L
  float gasPrice = 2.6; // R$
  float individualTollPrice = 8.0; // R$
  int tollAmount;
  float totalDistance, totalCost;

  printf("Por favor, insira a distância (em km) entre origem e destino: ");
  scanf("%f", &totalDistance);

  printf("Por favor, insira a quantidade de pedágios no trajeto: ");
  scanf("%d", &tollAmount);

  totalCost = ((totalDistance / efficiency) * gasPrice) + (tollAmount * individualTollPrice);

  printf("\nO custo total da viagem será: R$ %.2f", totalCost);
  return 0;
}