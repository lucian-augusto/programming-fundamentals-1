#include <stdio.h>

int main(void) {
  int i1, i2, divis, rest;

  printf("Por favor, insira o primeiro número inteiro: ");
  scanf("%d", &i1);

  printf("Por favor, insira o segundo número inteiro: ");
  scanf("%d", &i2);

  divis = i1 / i2;
  rest = i1 % i2;

  printf("O resultado da divisão de %d por %d é:\n%d, com resto %d", i1, i2, divis, rest);
  return 0;
}

// Como estamos utilizando valores inteiros, o resultado da divisão sempre será
// um valor inteiro e, caso o dividendo não seja divisível pelo divisor (isto é,
// o divisor não cabe um número inteiro de vezes dentro do dividendo), vamos ter
// também um resto associado a esta divisão. Neste programa estamos calculando
// justamente o quociente e o resto de uma divisão inteira. Portanto, para i1 = 10
// e i2 = 5 temos quociente 2 e resto 0 (afinal 5 cabe exatametne 2 vezes dentro 
// do 10) e, para i1 = 12 e i2 = 5 vamos ter um quociente 2 e resto 2 (afinal 5
// cabe 2 vezes dentro do 12, mas ainda faltam duas unidades para dar o valor 
// exato).