#include <stdio.h>
#include <ctype.h>
#include <math.h>

int main(void) {
  char option;
  float num1, num2, num3, result;

  // Reordenando para ler os valores antes do caractere
  printf("Por favor insira três valores para calcular a média (separados por espaço): ");
  scanf("%f %f %f", &num1, &num2, &num3);


  printf("Por favor, insira o caractere referente ao tipo de média você deseja calcular:\nA = média aritmética;\nP = média ponderada (com pesos 1, 2 e 3 para o primeiro, segundo e terceiro valor, respectivamente);\nG = média geométrica;\nH = média harmônica.\nTipo de média: ");
  scanf(" %c", &option); // Com espaço antes do identificador do tipo de variável 
  // para iognorar o caractere em branco presente no buffer do teclado
  option = tolower(option);

  if (option != 'a' && option != 'p' && option != 'g' && option != 'h') {
    printf("Opção Inválida");
    return 0;
  }

  if (option == 'a') {
    printf("\nCalculando a média aritmética: ");
    result = (num1 + num2 + num3) / 3;
  } 

  if (option == 'p') {
    printf("\nCalculando a média ponderada: ");
    result = (num1 + (2 * num2) + (3 * num3)) / (1 + 2 + 3);
  } 

  if (option == 'g') {
    printf("\nCalculando a média geométrica: ");
    result = cbrt(num1 * num2 * num3);
  } 

  if (option == 'h') {
    printf("\nCalculando a média harmônica: ");
    result =  3 / (pow(num1, -1) + pow(num2, -1) + pow(num3, -1));
  } 

  printf("\nMédia = %.3f", result);

  return 0;
}