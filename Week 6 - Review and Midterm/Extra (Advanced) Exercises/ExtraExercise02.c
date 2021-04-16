#include <stdio.h>
#define MIN 100
#define MAX 999

int calculateReverseNumber(int number) {
  int reverse = 0;
  while (number > 0) {
    reverse *= 10;
    reverse += number % 10;
    number /= 10;
  }
  return reverse;
}

int main(void) {
  int product, reverseProduct, i, j;
  int biggestPalindrome = 0;

  for (i = MIN; i <= MAX; i++) {
    for (j = MIN; j <= MAX; j++) {
      product = i * j;

      if (product == calculateReverseNumber(product) && product > biggestPalindrome) {
        biggestPalindrome = product;
      }
    }
  }
  printf("O maior palíndromo é: %d", biggestPalindrome);
  return 0;
}