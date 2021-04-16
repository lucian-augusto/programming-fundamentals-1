#include <stdio.h>
#include <math.h>
#define MIN 100
#define MAX 999

int main(void) {
  int num1, num2, i, j, currentDigit, num2PreviousEqualPosition;
  int num1Length = 0;
  int num2PositionCounter = 0;
  int sameDigitCounter = 0;
  int num2Collector = 0;
  
  while (1) {
    num1Length = 0;
    num2PositionCounter = 0;
    sameDigitCounter = 0;
    num2Collector = 0;
    printf("Por favor, insira o primeiro número de três dígitos: ");
    scanf("%d", &num1);

    printf("Agora insira o segundo número de três dígitos: ");
    scanf("%d", &num2);

    if (num1 < 0 || num2 < 0) {
      break;
    } 

    if (num1 < MIN || num1 > MAX || num2 < MIN || num2 > MAX) {
      printf("Número inserido não contém três dígitos");
      continue;
    }

    i = num1;
    while (i > 0) {
      currentDigit = i % 10;
      
      if (sameDigitCounter == 0) {
        j = num2;
      } else {
        j = num2Collector;
      }
      num2Collector = 0;
      num2PositionCounter = 0;
      while (j > 0) {
        if (j % 10 == currentDigit) {
          sameDigitCounter++;
          num2PreviousEqualPosition = num2PositionCounter;
          num2Collector += j / 10 * pow(10, num2PositionCounter);
          break;
        }
        num2Collector += (j % 10) * pow(10, num2PositionCounter);
        j /= 10;
        num2PositionCounter++;
      }

      i /= 10;
      num1Length++;
    }

    if (sameDigitCounter == num1Length) {
      printf("%d é uma permutação de %d\n", num2, num1);
    } else {
      printf("%d não é uma permutação de %d\n", num2, num1);
    }
  }

  return 0;
}