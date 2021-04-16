#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int n1, n2, operation, guessedResult, actualResult;
  char symbol;
  //clock_t startTime, endTime;
  double totalTime;

  // Inicializando a semente para gerar os valores aleatórios
  srand(time(NULL));

  // Gerando valores randômicos para n1 e n2
  n1 = rand() % 100;
  n2 = rand() % 100;

  // Escolhendo uma operação matemática aleatoriamente
  operation = rand() % 4;

  // Pedindo para o usuário fornecer o resultado da operação
  printf("Por favor, insira o resultado da operação abaixo:\n");

  // Preparando equação e símbolo da operação matemática
  if (operation == 0) {
    symbol = '+';
    actualResult = n1 + n2;
  } else if (operation == 1) {
    symbol = '-';
    actualResult = n1 - n2;
  } else if (operation == 2) {
    symbol = '*';
    actualResult = n1 * n2;
  } else if (operation == 3) {
    symbol = '/';
    actualResult = n1 / n2;
  } else {
    symbol = '%';
    actualResult = n1 % n2;
  }
  clock_t startTime = clock();
  printf("\n%d %c %d = ", n1, symbol, n2);
  // Marcando tempo inicial para o usuário responder
  scanf("%d", &guessedResult);

  // sleep(5);
  // Marcando o tempo após a resposta do usuário
  clock_t endTime = clock();
  
  totalTime = (double) (endTime - startTime) / CLOCKS_PER_SEC;

  if (guessedResult == actualResult ) {
    printf("Você acertou! ");
  } else {
    printf("Você Errou! ");
  }

  printf("%ld - %ld = %ld", endTime, startTime, endTime-startTime);
  printf("O resultado é: %d\nVocê demorou %lf", actualResult, totalTime);

  return 0;
}