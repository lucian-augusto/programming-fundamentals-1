#include <stdio.h>

int main(void) {
  const int consumptionTier[] = {0, 10, 30, 100}; // em m^3 
  const int priceTier[] = {0, 1, 2, 5}; // em R$
  const int consumptionTierLength = sizeof(consumptionTier) / sizeof(consumptionTier[0]);
  int consumption;
  int totalPrice = 7;
  int i;

  printf("Por favor, insira o consumo de água em m^3 (número inteiro): ");
  scanf("%d", &consumption);

  for (i = 1; i < consumptionTierLength; i++) {
    if (consumption <= consumptionTier[i]) {
      totalPrice += (consumption - consumptionTier[i-1]) * priceTier[i-1];
      break;
    } else {
      if (i == consumptionTierLength) {
        totalPrice += (consumption - consumptionTier[consumptionTierLength-1]) * priceTier[consumptionTierLength-1];
      } else {
        totalPrice += (consumptionTier[i] - consumptionTier[i-1]) * priceTier[i-1];
      }
    }
  } 

  if (consumption > consumptionTier[consumptionTierLength-1]) {
    totalPrice += (consumption - consumptionTier[consumptionTierLength-1]) * priceTier[consumptionTierLength-1];
  }

  printf("\nValor da conta: R$ %d,00", totalPrice);
  return 0;
}