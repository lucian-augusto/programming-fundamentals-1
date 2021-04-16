#include <stdio.h>
#include <stdlib.h>

int retornaMaior(int n1, int n2) {
  return (n1 + n2 + abs(n1 - n2)) / 2;
}

int main(void) {
  int n1, n2, n3, biggestNumber;
  
  printf("Por favor, insira 3 números inteiros: ");
  scanf("%d %d %d", &n1, &n2, &n3);

  biggestNumber = retornaMaior(n1, n2);
  biggestNumber = retornaMaior(biggestNumber, n3);

  printf("O Maior valor digitado foi %d", biggestNumber);
  return 0;
}