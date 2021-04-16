#include <stdio.h>

int main(void) {
  int num, i, j;

  printf("Digite o tamanho da bandeira (número inteiro e maior do que 1): ");
  scanf("%d", &num);

  while (num < 2) { // Validação da entrada do tamanho da bandeira (impossíível 
  //criar o padrão quando num < 2)
    printf("Não é possível confeccionar uma bandeira com tamanho menor do que 2.\nTente outro tamanho: ");
    scanf("%d", &num);
  }

  // Imprimindo parte superior da bandeira
  for (i = num; i > 0; i--) {
    for (j = i; j > 0; j--) {
      printf("*");
    }
    printf("\n");
  }
  // Imprimindo a parte inferior da bandeira (descontando a primeira linha do 
  //triângulo que já foi imprimida na parte superior)
  for (i = 2; i <= num; i++) {
    for (j = 0; j < i; j++) {
      printf("*");
    }
    printf("\n");
  }
  return 0;
}