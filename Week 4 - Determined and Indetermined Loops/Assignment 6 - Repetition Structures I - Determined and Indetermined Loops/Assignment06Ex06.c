#include <stdio.h>

int main(void) {
  int number, factorial;
  int i;
  printf("Por favor, insira um número inteiro e maior que zero para calcular o fatorial: ");
  scanf("%d", &number);

  if (number < 0) {
    printf("\n%d é menor que zero, portanto seu fatorial não pertence ao conjunto dos números reais.", number);
    return 0;
  }

  factorial = number;
  for (i = number - 1; i > 0; i--) {
    factorial *= i; 
  }

  printf("%d! = %d", number, factorial);
  return 0;
}

/* Utilizando uma variável do tipo 'int', o cálculo de fatorial funciona 
perfeitamente até o número 12. De 13 em diante o resultado simplesmente para de 
fazer sentido, sendo muito inferior ao valor real. Isto ocorre porque a variável 
do tipo int consegue armazenar apenas 4 bytes de informação, isto é, ela consegue 
manter apenas valores entre -2,147,483,648 e 2,147,483,647, que é inferior a 13!
(6,227,020,800). Para resolver este problema podemos utilizar uma variável do tipo 
unsigned int (que efetivamente dobra o número que uma variável int é capaz de 
segurar - pois segura apenas numeros maiores que zero), mas ainda estaríamos 
limitando o maior fatorial que poderíamos calcular em 13!. Para ir além disso, é 
necessário utilizar variáveis capazes de segurar uma quantidade maior de informação
como o long (que segura 8 bytes - números de -9223372036854775808 até 
9223372036854775807) ou então unsigned long (que efetivamente dobra o valor 
númerico a variável long é capaz de segurar mas aceita apenas números positivos).
*/