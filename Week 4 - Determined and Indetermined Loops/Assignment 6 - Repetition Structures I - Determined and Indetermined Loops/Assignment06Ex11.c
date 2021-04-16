#include <stdio.h>

int main(void) {
  const int password = 2002;
  int isCorrect = 0;
  int input;

  while (!isCorrect) {
    printf("Digite a senha: ");
    scanf("%d", &input);

    if (input == password) {
      isCorrect = 1;
    } else {
      printf("Senha Inválida\n");
    }
  }

  printf("Acesso Permitido");
  return 0;
}