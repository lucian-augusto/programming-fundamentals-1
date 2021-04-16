#include <stdio.h>
//#include <math.h> 
/* Usando a função abs() da biblioteca math.h, resulta em 
um warning:
"implicitly declaring library function 'abs' with type
      'int (int)' [-Wimplicit-function-declaration]
  highest = (n1 + n2 + abs(n1 - n2)) / 2;
                       ^
main.c:16:24: note: include the header <stdlib.h> or explicitly provide a
      declaration for 'abs'"
Portanto, para evitar o warning vou utilizar a biblioteca
stdlib.h como sugerido pelo compilador do repl.it.
*/
#include <stdlib.h>

int main(void) {
  int n1, n2, n3, highest;

  printf("Por favor, insira o primeiro valor inteiro: ");
  scanf("%d", &n1);

  printf("Por favor, insira o segundo valor inteiro: ");
  scanf("%d", &n2);

  printf("Por favor, insira o terceiro valor inteiro: ");
  scanf("%d", &n3);

  highest = (n1 + n2 + abs(n1 - n2)) / 2;

  highest = (highest + n3 + abs(highest - n3)) / 2;

  printf("\n%d eh o maior", highest);
  return 0;
}