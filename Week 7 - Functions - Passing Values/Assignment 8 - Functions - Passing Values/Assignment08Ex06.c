#include <stdio.h>

int retornaResto(int alexandre, int maria, int rafael) {
  return (alexandre + maria + rafael) % 3;
}

void imprimeVencedor(int resto) {
  if (resto == 0) {
    printf("Alexandre é o vencedor!");
  } else if (resto == 1) {
    printf("Maria é a vencedora!");
  } else if (resto == 2) {
    printf("Rafael é o vencedor!");
  } else {
    printf("Erro!!");
  }
}

int main(void) {
  int n1, n2, n3, result;

  printf("Digite os valores para Alexandre, Maria e Rafael respectivamente: ");
  scanf("%d %d %d", &n1, &n2, &n3);

  result = retornaResto(n1, n2, n3);

  imprimeVencedor(result);
  return 0;
}