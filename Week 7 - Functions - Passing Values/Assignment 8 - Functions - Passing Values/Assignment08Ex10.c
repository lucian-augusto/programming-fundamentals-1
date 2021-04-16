#include <stdio.h>

int retornaMDC(int num1, int num2);
int getNonZeroInteger();

int retornaMDC(int num1, int num2) {
  while (num1 != num2) {
    if (num1 - num2 < 0) {
      num2 -= num1;
    } else {
      num1 -= num2;
    }
  }
  return num1;
}

int getNonZeroInteger() {
  int num;
  printf("Por Favor, entre um número inteiro e diferentes de zero: ");
  scanf("%d", &num);
  
  while (num == 0) {
    printf("O número inserido não pode ser igual a zero. Por favor, tente novamente: ");
    scanf("%d", &num);
  }
  return num;
}

int main(void) {
  int gcd, n1, n2;

  n1 = getNonZeroInteger();
  n2 = getNonZeroInteger();

  gcd = retornaMDC(n1, n2);
  printf("O Máximo divisor comum entre %d e %d é: %d", n1, n2, gcd);
  return 0;
}