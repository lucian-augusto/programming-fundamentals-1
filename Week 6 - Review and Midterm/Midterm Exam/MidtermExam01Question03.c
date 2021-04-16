#include <stdio.h>

int main(void) {
  int sequenceLength, currentNumber, previousNumber, startingPosition, i;
  int isOnSequence = 0;
  int repetition = 1;
  int previousRepetition = 0;
  int score = 0;
  
  printf("Por favor, insira o tamanho da sequência: ");
  scanf("%d", &sequenceLength);

  while (sequenceLength < 2) { // validação do tamanho da sequência sequenceLength 
  // deve ser maior ou igual a dois para existir uma sequência
    printf("É necessário pelo menos 2 elementos para caracterizar uma sequência. Tente outro tamanho: ");
    scanf("%d", &sequenceLength);
  }

  printf("Insira agora a sequência de %d números:\n", sequenceLength);
  for (i = 1; i <= sequenceLength; i++) {
    scanf("%d", &currentNumber);

    if (currentNumber == previousNumber && i != 1) {
      if (!isOnSequence) { // Início de uma nova sequência. Salvando posiçãão 
      // inicial e alterando a flag
        isOnSequence = 1;
        startingPosition = i - 1;
      }
      repetition++; 
      if (repetition >= previousRepetition) { // Verificando se o número de 
      // repetiçõões atual é maior do que qualquer repetição anterior
        score = repetition * startingPosition;
        previousRepetition = repetition;
      }
      
    } else {
      // Resetando variáveis da repetição
      isOnSequence = 0;
      repetition = 1;
    }
    previousNumber = currentNumber;
  }

  printf("%d", score);
  return 0;
}