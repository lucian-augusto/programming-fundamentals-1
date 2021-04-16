#include <stdio.h>
#include <math.h>

int getNumberLength(int number);

int calculaDigitoVerificador(int num) {
  int i;
  int checkDigit = 0;
  if (getNumberLength(num) != 3) {
    return -1;
  }
  int numLength = getNumberLength(num);
  for (i = 1; i <= numLength; i++) {
    checkDigit += (i * (num / (int)pow(10, numLength - i)));
    num %= (int)pow(10, numLength - i);
  }
  return (checkDigit % 11) % 10;
}

int getNumberLength(int number) {
  int count = 0;

  if (number < 0) {
    return -1;
  }

  while (number > 0) {
    number /= 10;
    count++;
  }
  return count;
}

int main(void) {
  int num[] = {193, 542, 702, 900, 777, 100, 45, -777};
  int numLength = sizeof(num)/sizeof(num[0]);
  int i, checkDigit;

  for (i = 0; i < numLength; i++) {
    checkDigit = calculaDigitoVerificador(num[i]);
    if (checkDigit < 0) {
      printf("%d não é um número válido\n", num[i]);
    } else {
      printf("Dígito Verificador de %d: %d\n", num[i], checkDigit);
    }
  }
  return 0;
}