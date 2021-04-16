#include <stdio.h>

int main(void) {
  int n1, n2; 
  float media;

  printf("Por favor, insira o primeiro número inteiro: ");
  scanf("%d", &n1);

  printf("Por favor, insira o segundo número inteiro: ");
  scanf("%d", &n2);

  media = (n1 + n2) / 2.0;

  printf("A média entre %d e %d é: %f", n1, n2, media);
  return 0;
}

// Para corrigir o código e calcular corretamente a média, basta transformar uma 
// das partes da divisão (dividendo ou divisor) em um número inteiro (com ponto 
// flutuante). Portanto, podemos usar "2.0" em vez de "2" na fórmula da média ou 
// então, transformaras variáveis "n1" e "n2" em floats. Mas como o enunciado pede 
// para que as variáveis recebam valores inteiros, vamos apenas dividir sua soma 
// por "2.0" em vex de "2"