#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

int main(void) {
  srand(time(NULL));
  int magicNumber = (rand() % 500) + 1;
  int count = 0;
  int guess;

  printf("Tente adivinhar o número mágico :D\nEste número é um número aleatório entre 1 e 500 (incluindo estes dois)");
  while (guess != magicNumber && guess != -1) {
    printf("\nPor favor, insira um número inteiro e maior que zero (insira -1 para sair do programa): ");
    scanf("%d", &guess);
    count++;

    if (guess > magicNumber) {
      printf("\nResposta errada. Tente um número menor ;).");
    }
    if (guess < magicNumber && guess != -1) {
      printf("\nResposta errada. Tente um número maior ;).");
    }
  }

  if (guess == -1) {
    printf("\nAté a próxima ;).");
    return 0;
  } 

  printf("\nVocê acertou o número mágico em %d tentativas\n", count);
  if (count < 4) {
    printf("\\o/");
  } else if (count < 7) {
    printf(":-D");
  } else if (count < 11) {
    printf(":-)");
  } else {
    printf(":-/");
  }
  return 0;
}