#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int haveSameEnding(int a, int b);
int isSegment(int a, int b);
void isSegmentTest(int a, int b);
int getBiggestNumber(int num1, int num2);
int calculateNumberLength(int number);

int isSegment(int a, int b) {
  int isSegment = 0;
  int areReversed = 0;
  int biggestNumber = getBiggestNumber(a, b);
  int biggestNumberLength = calculateNumberLength(biggestNumber);
  int i;

  if (b > a) {
    areReversed = 1;
  }

  for (i = 0; i < biggestNumberLength; i++) {
    if (areReversed) {
      isSegment = haveSameEnding(biggestNumber, a);
    } else {
      isSegment = haveSameEnding(biggestNumber, b);
    }
    if (isSegment) {
      break;
    }
    biggestNumber /= 10;
  }

  if (!isSegment) {
    return 0;
  }
  if (areReversed) {
    return 1;
  }
  return 2;
}

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

int getBiggestNumber(int num1, int num2) {
  return (num1 + num2 + abs(num1 - num2)) / 2;
}

void isSegmentTest(int a, int b) {
  printf("%d\n", isSegment(a, b));
}

int main(void) {
  isSegmentTest(1243, 2212435);
  isSegmentTest(567890, 678);
  isSegmentTest(235, 236);
  return 0;
}