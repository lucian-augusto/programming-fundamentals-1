#include <stdio.h>

int main(void) {
  long totalAmount;
  int seconds, minutes, hours, days;

  printf("Por favor, insira o número total de segundos: ");
  scanf("%ld", &totalAmount);

  minutes = totalAmount / 60;
  seconds = totalAmount % 60;

  hours = minutes / 60;
  minutes = minutes % 60;

  days = hours / 24;
  hours = hours % 24;

  printf("\n%ld segundos correspondem a %d dias, %d horas, %d minutos e %d segundos", totalAmount, days, hours, minutes, seconds);
  return 0;
}