#include <stdio.h>

int main(void) {
  int number, i, j, isPrime;
  int sum = 0;

  printf("Por favor, insira um número inteiro: ");
  scanf("%d", &number);
  
  i = 2;
  while (i <= number) {
    isPrime = 1;
    for (j = 2; j < i; j++) {
      if (i % j == 0) {
        isPrime = 0;
        break;
      }
    }

    if (isPrime) {
      sum += i;
    }

    if (i == 2) {
      i++;
    } else {
      i += 2;
    }
  }

  printf("A soma dos números primos de zero até %d é: %d", number, sum);
  return 0;
}