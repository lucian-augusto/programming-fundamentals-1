#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int num1, num2, smallest, biggest, i;
  int numberOfOdds = 0;

  printf("Por favor, insira dois números inteiros: ");
  scanf("%d %d", &num1, &num2);

  smallest = (num1 + num2 - abs(num1 - num2)) / 2;
  biggest = (num1 + num2 + abs(num1 - num2)) / 2;

  for (i = smallest + 1; i < biggest; i++) {
    if (i % 2 != 0) {
      numberOfOdds++;
    }
  }

  printf("\n%d", numberOfOdds);
  return 0;
}