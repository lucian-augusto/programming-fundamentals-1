#include <stdio.h>

int main(void) {
  float chicosHeight = 1.5;
  float zesHeight = 1.1;
  const float chicosYearlyGrowth = 0.02;
  const float zesYearlyGrowth =  0.03;
  int years = 0;
  
  while (chicosHeight >= zesHeight) {
    chicosHeight += chicosYearlyGrowth;
    zesHeight += zesYearlyGrowth;
    years++;
  }

  printf("Serão necessários %d anos para Zé ser maior que Chico", years);
  return 0;
}