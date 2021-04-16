#include <stdio.h>

int sequenceVerifier(int n);
int isPyramidal(int length);
void printResult(int result);
int sequenceLengthInput();

// (a)
int sequenceVerifier(int n) {
  int sequence[n];
  int i;
  int evenCounter = 0;
  int oddCounter = 0;

  for (i = 0; i < n; i++) {
    scanf("%d", &sequence[i]);

    if (sequence[i] % 2 == 0) {
      evenCounter++;
    } else {
      oddCounter++;
    }
  }

  if (evenCounter != 0 && oddCounter != 0) {
    return -1;
  }
  if (evenCounter > 0) {
    return 0;
  }
  return 1;
}

// (b)
int isPyramidal(int length) {
  int isPyramidal = 1;
  int pyramidLevel = 0;
  int currentLevel, previousLevel;

  while (length > 0 && isPyramidal) {
    pyramidLevel++;
    if (length < pyramidLevel) {
      printf("%d é um tamanho insuficiente para uma sequência piramidal alternante\n", length + pyramidLevel);
      isPyramidal = 0;
      break;
    }
    currentLevel = sequenceVerifier(pyramidLevel);

    if ((currentLevel == previousLevel || currentLevel == -1) && pyramidLevel != 1) {
      isPyramidal = 0;
    }
    previousLevel = currentLevel;

    length -= pyramidLevel;
  }
  if (isPyramidal) {
    return pyramidLevel;
  }
  return 0;
} 

void printResult(int result) {
  if (result > 0) {
    printf("A sequência inserida é piramidal %d-alternante.", result);
  } else {
    printf("A sequência inseria não é piramidal alternante.");
  }
}

int sequenceLengthInput() {
  int input; 

  printf("Insira o tamanho da sequêcia que deseja verificar: ");
  scanf("%d", &input);

  while (input < 2) {
    printf("Não é possível ter uma sequência com %d termos. Tente novamente: ", input);
    scanf("%d", &input);
  }
  
  printf("Insira os %d termos da sequência para verificarmos se ela é piramidal alternante ou não:\n", input);

  return input;
}

int main(void) {
  int input, result;

  input = sequenceLengthInput();

  result = isPyramidal(input);
  printResult(result);
  return 0;
}