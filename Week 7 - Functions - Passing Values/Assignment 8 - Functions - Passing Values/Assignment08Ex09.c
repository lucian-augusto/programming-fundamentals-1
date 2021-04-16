#include <stdio.h>
#include <math.h>

float calculaIMC(float altura, float peso);
void imprimeMsgIMC(float imc);

float calculaIMC(float altura, float peso) {
 return peso / pow(altura, 2);
}

void imprimeMsgIMC(float imc) {
  if (imc < 18.5) {
    printf("Você está abaixo do peso.");
  } else if (imc >= 18.5 && imc < 25) {
    printf("Você está com o peso normal.");
  } else if (imc >= 25 && imc < 30) {
    printf("Você está acima do peso.");
  } else {
    printf("Você está obeso.");
  }
}

int main(void) {
  float height, weight, bmi;

  printf("Por favor, insira a sua altura (em m): ");
  scanf("%f", &height);

  printf("Por favor, insira o seu peso (em kg): ");
  scanf("%f", &weight);

  bmi = calculaIMC(height, weight);

  imprimeMsgIMC(bmi);
  return 0;
}