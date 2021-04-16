#include <stdio.h>

int main() {
  float n1, n2, aux;
  
  printf("Digite o primeiro valor: ");
  scanf("%f", &n1);

  //.......... COMPLETAR ..........

  printf("Digite o segundo valor: ");
  scanf("%f", &n2);

  aux = n1 + n2;
  
  printf("A soma de %.2f e %.2f é: %.2f", n1, n2, aux);
  return 0;
}

// Caso seja retirado os comandos de leitura, o código irá continuar rodando, ou
// seja, ele irá continuar a executar as intruções de impressão. Entretanto, ao 
// imprimir o valor das variáveis, o programa irá imprimir o valor que está 
// relacionado a ela no momento da declaração, normalmente, um valor presente no 
// espaço de memória em que a variável foi criada, ou então, no caso do Repl.it,
// que roda em uma máquina virtual, zero.
