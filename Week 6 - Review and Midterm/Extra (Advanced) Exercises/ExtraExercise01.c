#include <stdio.h>

int main(void) {
  int input, previousInput, number, i;
  int segmentLength = 0;
  int maxSegmentLength = 0;

  printf("Por favor, insira o tamanho da sequência: ");
  scanf("%d", &number);

  if (number <= 0) {
    printf("A sequência não pode ter menos do que 1 elemento.");
    return 0;
  }

  printf("Agora insira %d números:\n", number);
  for (i = 0; i < number; i++) {
    scanf("%d", &input);

    if (input <= previousInput) {
      segmentLength = 0;
    }
    previousInput = input;
    segmentLength++;
    if (segmentLength > maxSegmentLength) {
      maxSegmentLength = segmentLength;
    }
  }

  printf("O comprimento do segmento crescente máximo é %d", maxSegmentLength);
  return 0;
}