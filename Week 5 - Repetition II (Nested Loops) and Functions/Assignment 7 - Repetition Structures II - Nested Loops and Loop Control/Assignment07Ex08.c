#include <stdio.h>

int main(void) {
  int number, processedNumber, div, rest;
  int areTheSame = 1;

  printf("Por favor, insira um número inteiro: ");
  scanf("%d", &number);

  if (number / 10 == 0) {
    printf("%d é formado por apenas um algarismo.", number);
    return 0;
  }
  
  processedNumber = number;
  do {
    div = processedNumber / 10;
    if (div != 0 && (processedNumber % 10) != (div % 10)) {
      areTheSame = 0;
    }
    processedNumber = div;
  } while (processedNumber > 0 && areTheSame);

  printf("\n%d ", number);
  if (!areTheSame) {
    printf("não ");
  } 
  printf("é composto por algarismos iguais.");
  return 0;
}