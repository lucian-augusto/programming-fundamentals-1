#include <stdio.h>

int main(void) {
  int number = 0;
  
  printf("Por favor, insira números inteiros (número negativo sai do loop): ");
  while (number >= 0) {
    scanf("%d", &number);
  }

  printf("%d < 0, Fim", number);
  return 0;
}