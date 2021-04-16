#include <stdio.h>

int main(void) {
  int numberOfStudents, numberOfPrefects;

  printf("Por favor, insira o número de alunos: ");
  scanf("%d", &numberOfStudents);

  printf("Por favor, insira o número de monitores: ");
  scanf("%d", &numberOfPrefects);

  if (numberOfPrefects + numberOfStudents > 50) {
    printf("Não é possível levar todos os alunos e monitores em uma única viagem.");
  } else {
    printf("É possível levar todos os alunos e monitores em uma única viagem.");
  }
  return 0;
}