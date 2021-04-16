#include <stdio.h>

int main(void) {
  int lat, cop;
  int brokenGlasses = 0;

  printf("Por favor insira o número de de latas e copos (inteiros e em ordem)\nPara sair, entre zero apra ambos os valores: " );
  scanf("%d %d", &lat, &cop);
  while (lat != 0 || cop != 0) {
    if (lat > cop) {
      brokenGlasses += cop;
    }

    printf("Por favor insira o número de de latas e copos (inteiros e em ordem)\nPara sair, entre zero apra ambos os valores: " );
    scanf("%d %d", &lat, &cop);
  }

  printf("\nQuebrou %d copos.\n", brokenGlasses);
  return 0;
}