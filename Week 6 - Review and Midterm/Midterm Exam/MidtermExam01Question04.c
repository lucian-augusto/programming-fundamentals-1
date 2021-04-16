#include <stdio.h>

int main(void) {
  int pollTotalAmount, i;
  int maleYes = 0;
  int maleNo = 0;
  int femaleYes = 0;
  int femaleNo = 0;
  char gender, answer;

  printf("Por favor, insira o número de pessoas entrevistadas: ");
  scanf("%d", &pollTotalAmount);

  for (i = 0; i < pollTotalAmount; i++) {
    printf("Por favor, forneça seu sexo, (f)eminino ou (m)asculino e sua resposta, (s)im ou (n)ão: ");
    scanf(" %c %c", &gender, &answer);

    if (gender == 'f' && answer == 's') {
      femaleYes++;
    } else if (gender == 'f' && answer == 'n') {
      femaleNo++;
    } else if (gender == 'm' && answer == 's') {
      maleYes++;
    } else if (gender == 'm' && answer == 'n') {
      maleNo++;
    } else {
      printf("Entrada inválida!\n");
    }
  }

  printf("\n%d pessoas responderam sim", femaleYes + maleYes);
  printf("\n%d pessoas responderam não", femaleNo + maleNo);
  printf("\n%.2f das pessoas do sexo feminino respoderam sim", 100 * ( (float)femaleYes / (femaleNo + femaleYes)));
  printf("\n%.2f das pessoas do sexo masculino respoderam não", 100 * ( (float) maleNo / (maleNo + maleYes)));
  return 0;
}