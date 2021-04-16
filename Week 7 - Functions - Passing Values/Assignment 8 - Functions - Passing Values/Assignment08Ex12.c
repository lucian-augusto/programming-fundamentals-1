#include <stdio.h>
#include <math.h>

int haveSameEnding(int a, int b);
void haveSameEndingTest(int a, int b);
int calculateNumberLength(int number);

int haveSameEnding(int a, int b) {
  int significantA;
  if (a < 0 || b < 0 || b > a) {
    return 0;
  }
  significantA = a % (int) pow(10, calculateNumberLength(b));

  if (significantA == b) {
    return 1;
  }
  return 0;
}

int calculateNumberLength(int number) {
  int count = 0;
  while (number > 0) {
    number /= 10;
    count++;
  }
  return count;
}

void haveSameEndingTest(int a, int b) {
  printf("%d\n", haveSameEnding(a, b));
}

int main(void) {
  haveSameEndingTest(567890, 890);
  haveSameEndingTest(1243, 1243);
  haveSameEndingTest(2457, 245);
  return 0;
}