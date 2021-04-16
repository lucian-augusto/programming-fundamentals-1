#include <stdio.h>

int main(void) {
  float tempC, tempF;

  printf("Por favor, insira a temperatura em celsius: ");
  scanf("%f", &tempC);

  tempF = ((9.0 / 5) * tempC) + 32;

  printf("\nA temperatura em fahrenheit é: %.3f ˚F", tempF);
  return 0;
}