#include <stdio.h>

int main(void) {
  int sequenceLength, pastNumber, currentNumber, i;
  int isAsc = 1;

  printf("Por favor, insira um número (inteiro e maior que zero): ");
  scanf("%d", &sequenceLength);

  if (sequenceLength < 1) {
    printf("%d não é maior que zero.", sequenceLength);
    return 0;
  }

  printf("Insira agora uma sequência de %d números (inteiros): ", sequenceLength);
  for (i = 0; i < sequenceLength; i++) {
    scanf("%d", &currentNumber);
    
    if (i == 0 || currentNumber > pastNumber) {
      pastNumber = currentNumber;
    } else {
      isAsc = 0;
    }
  }

  printf("\nA sequência é crescente: \n");
  if (isAsc) {
    printf("Sim");
  } else {
    printf("Não");
  }
  return 0;
}