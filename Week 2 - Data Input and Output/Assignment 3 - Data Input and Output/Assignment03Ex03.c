#include <stdio.h>

int main(void) {
  char charVariable;
  int intVariable;
  float floatVariable;

  printf("Por favor, entre um caractere: ");
  scanf("%c", &charVariable);

  printf("Por favor, entre um número inteiro (sem ponto flutuante): ");
  scanf("%d", &intVariable);

  printf("Por favor, entre um número inteiro (ponto flutuante é váldio): ");
  scanf("%f", &floatVariable);

  printf("Os valores das variáveis que você entrou são:\n");
  printf("'char': %c;\n'int': %d;\n'float': %f.\n", charVariable, intVariable, floatVariable);
  return 0;
}