#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int a, b, c, h, l, smallestDim1, smallestDim2;

  printf("Insira as dimensões da caixa (em cm): ");
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);

  smallestDim1 = (a + b - abs(a - b)) / 2;
  smallestDim2 = (b + c - abs(b - c)) / 2;


  printf("\nInsira as dimensões da janela (em cm): ");
  scanf("%d", &h);
  scanf("%d", &l);

  if ((h > smallestDim1 && l > smallestDim2) || (h > smallestDim2 && l > smallestDim1)) {
    printf("S");
  } else {
    printf("N");
  }
  
  return 0;
}