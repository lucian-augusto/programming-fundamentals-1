#include <stdio.h>

int isRegular(int number) {
  int basePrimes[] = {2, 3, 5, 7}; 
  int basePrimesIndex = 0;
  int isRegular = 1;

  while (number > 1) {
    if (basePrimes[basePrimesIndex] > 5) {
      isRegular = 0;
      break;
    }
    if (number % basePrimes[basePrimesIndex] == 0) {
      number /= basePrimes[basePrimesIndex];
    } else {
      basePrimesIndex++;
    }
  }
  return isRegular;
}

void isRegularTest(int number) {
  printf("%d\n", isRegular(number));
}

int main(void) {
  isRegularTest(60);
  isRegularTest(45);
  isRegularTest(777);
  isRegularTest(10);
  isRegularTest(13);
  return 0;
}