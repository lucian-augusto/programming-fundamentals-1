#include <stdio.h>

int ehBissexto(int ano) {
  if (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0)) {
    return 1;
  }
  return 0;
}

void ehBissextoTester(int year) {
  printf("%d ", year);
  if (!ehBissexto(year)) {
    printf("não ");
  }
  printf("é bissexto.\n");
}

int main(void) {
  ehBissextoTester(1992);
  ehBissextoTester(1999);
  ehBissextoTester(2000);
  ehBissextoTester(2001);
  ehBissextoTester(2019);
  ehBissextoTester(2020);
  ehBissextoTester(2021);
  return 0;
}