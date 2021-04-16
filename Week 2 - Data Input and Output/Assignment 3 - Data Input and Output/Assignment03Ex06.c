#include <stdio.h>

int main(void) {
  int n1, n2; 
  float media;

  printf("Por favor, insira o primeiro número inteiro: ");
  scanf("%d", &n1);

  printf("Por favor, insira o segundo número inteiro: ");
  scanf("%d", &n2);

  media = (n1 + n2) / 2;

  printf("A média entre %d e %d é: %f", n1, n2, media);
  return 0;
}

// O código acima funciona apenas quando a soma de n1 e n2 é par (que será 
// divisível por 2, resultando em um valor inteiro), mas quando esta soma for ímpar
// o resultado da divisão por 2 resultará em um valor não inteiro e, como estamos 
// usando uma divisão entre valores inteiros, o resultado estará incorreto. 
// A correção deste problema está no arquivo Assignment03Ex06Fix.c 