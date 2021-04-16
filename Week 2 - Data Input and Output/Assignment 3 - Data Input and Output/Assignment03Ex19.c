#include <stdio.h>

int main(void) {
  float n1, n2, n3, finalGrade;

  printf("Por favor, insira as notas do aluno (de zero a 10, em ordem e separadas por espaço): ");
  scanf("%f %f %f", &n1, &n2, &n3);

  finalGrade = (.2 * n1) + (.3 * n2) + (.5 * n3); 

  printf("\nA nota final do aluno é: %.1f", finalGrade);
  return 0;
}