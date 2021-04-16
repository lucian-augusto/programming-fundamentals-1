#include <stdio.h>

void determinaValores(int n);
int isSumEquals(int targetNumber, int a, int b, int c); 
int captureInput();

void determinaValores(int n) {
  int i, j, k;

  for (i = 1; i < n; i++) {
    for (j = 1; j < n; j++) {
      for (k = 1; k < n; k++) {
        if (isSumEquals(n, i, j, k)) {
          printf("%d + %d + %d = %d\n", i, j, k, n);
        }
      }
    }
  }
}

int isSumEquals(int targetNumber, int a, int b, int c) {
  int sum = a + b + c;
  if (sum == targetNumber) {
    return 1;
  } 
  return 0;
}

int captureInput() {
  int input = -1;

  printf("Por favor, insira um número inteiro maior do que zero: ");
  scanf("%d", &input);
  
  while (input <= 0) {
    printf("%d não é um número maior que zero. Tente novamente: ", input);
    scanf("%d", &input);
  }
  return input;
}

int main(void) {
  int num = captureInput();

  determinaValores(num);
  return 0;
}