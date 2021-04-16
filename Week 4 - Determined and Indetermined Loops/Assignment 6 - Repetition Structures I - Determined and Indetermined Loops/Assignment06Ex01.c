#include <stdio.h>
#define LOOP_LIMIT 10

int main(void) {
  int number, i;
  printf("Por favor, insira um número (inteiro): ");
  scanf("%d", &number);

  printf("\nA tabuada do %d é:", number);
  for (i = 1; i <= LOOP_LIMIT; i++) {
    printf("\n%d x %d = %d", number, i, number * i);
  }

  return 0;
}