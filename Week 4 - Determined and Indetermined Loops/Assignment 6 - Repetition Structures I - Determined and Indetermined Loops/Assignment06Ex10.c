#include <stdio.h>

float inputCapture() {
  float input;
  printf("Por favor insira um número (-1000 calcula a média dos valores positivos e encerra o programa): ");
  scanf("%f", &input);
  return input;
}

int main(void) {
  int count = 0;
  float sumOfPositives = 0;
  float input;
  
  input = inputCapture();
  while (input != -1000) {
    if (input > 0) {
      sumOfPositives += input;
      count++;
    } 
    input = inputCapture();
  }

  if(count == 0) {
    printf("Nenhum valor positivo inserido");
    return 0;
  }
  printf("\n%d valores positivos", count);
  printf("\nMédia dos valores positivos = %.1f", sumOfPositives / count);
  return 0;
}