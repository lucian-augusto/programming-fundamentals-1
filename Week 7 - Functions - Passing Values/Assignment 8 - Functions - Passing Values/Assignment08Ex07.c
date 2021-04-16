#include <stdio.h>
#include <math.h>

int bin2dec(int num);
int dec2bin(int num);
int optionSelection();

int bin2dec(int num) {
  int decNum = 0;
  int power = 0;

  while (num > 0) {
    decNum += (num % 10) * pow(2, power);
    num /= 10;
    power++;
  }
  return decNum;
}

int dec2bin(int num) {
  int binNum = 0;
  int count = 0;

  while (num > 0) {
    binNum += (num % 2) * pow(10, count);
    num /= 2;
    count++;
  }
  return binNum;
}

int optionSelection() {
  int option;
  
  printf("Escolha uma opção de conversão:\n(1) - Binário p/ Decimal;\n(2) - Decimal para Binário;\n(0) - Para sair:\n");
  scanf("%d", &option);
  if (option > 2 || option < 0) {
    printf("Opção Inválida! Tente novamente.\n");
    option = optionSelection();
  }
  return option;
}

int main(void) {
  int option, num;

  do {
    option = optionSelection();

    if (option == 1) {
      printf("Insira o número binário a ser convertido para decimal: ");
      scanf("%d", &num);
      printf("%d em decimal é: %d\n\n", num, bin2dec(num));
    } else if (option == 2) {
      printf("Insira o número decimal a ser convertido para binário: ");
      scanf("%d", &num);
      printf("%d em binário é: %d\n\n", num, dec2bin(num));
    }
  } while (option);
  return 0;
}