#include <stdio.h>

int main(void) {
  int sequenceLength, pastNumber, currentNumber, i;
  int isAsc = 1;
  int isDesc = 1;

  printf("Por favor, insira um número (inteiro e maior que zero): ");
  scanf("%d", &sequenceLength);

  if (sequenceLength <= 1) {
    printf("Impossível definir uma sequência com %d termos", sequenceLength);
    return 0;
  }

  printf("Insira agora uma sequência de %d números (inteiros): ", sequenceLength);
  for (i = 0; i < sequenceLength; i++) {
    scanf("%d", &currentNumber);
    
    if (i == 0) {
      pastNumber = currentNumber;
    } else {
      if (currentNumber > pastNumber) {
        isDesc = 0;
      } 
      if (currentNumber < pastNumber) {
        isAsc = 0;
      }
      pastNumber = currentNumber;
    }
  }

  printf("\nA sequência é ");
  if (isAsc == isDesc) {
    printf("desordenada");
  } else {
    if (isAsc) {
      printf("crescente");
    } 
    if (isDesc) {
      printf("decrescente");
    }
  }
  return 0;
}