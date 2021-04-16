#include <stdio.h>

int main(void) {
  int age, evaluation;
  int score = 0;
  int escapeFlag = 0;


  while (!escapeFlag) {
    printf("\nPor favor, insira a sua idade e a sua opinião sobre o filme seguindo a seuinte escala:\n");
    printf("(1) ótimo,\n(2) bom,\n(3) regular,\n(4) ruim ou\n(5) péssimo\n(-1) para sair: ");
    scanf("%d", &age);
    if (age == -1) {
      escapeFlag = 1;
    }
    if (!escapeFlag) {
      scanf("%d", &evaluation);
      if (evaluation == 5) {
        score += 0;
      } else if (evaluation == 4) {
        if (age < 18) {
          score += 2;
        } else if (age > 40) {
          score += 5;
        } else {
          score += 3;
        }
      } else if (evaluation == 3) {
        if (age < 18) {
          score += 3;
        } else if (age > 40) {
          score += 8;
        } else {
          score += 5;
        }
      } else if (evaluation == 2) {
        if (age < 18) {
          score += 4;
        } else if (age > 40) {
          score += 12;
        } else {
          score += 7;
        }
      } else if (evaluation == 1) {
        if (age < 18) {
          score += 5;
        } else if (age > 40) {
          score += 15;
        } else {
          score += 10;
        }
      } else {
        printf("Nota inválida");
      }
    }
  }

  printf("Pontuacao = %d", score);
  return 0;
}