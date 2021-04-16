/* Respostas:
1- Qual será a saída se atribuirmos no início os valores 1, 2 e 3 a n1, n2 e n3, respectivamente?
R: A saída será: 1 2 3

2- Qual será a saída se atribuirmos no início os valores 20, 10 e 30 a n1, n2 e n3, respectivamente?
R: A saída será: 10 20 30

3- Qual será a saída se atribuirmos no início os valores 5*5, n1/2 e n2+1 a n1, n2 e n3, respectivamente?
R: A saída será: 12 13 25

4- (****) O que o programa faz, exatamente? Explique o funcionamento do algoritmo.
R: O programa reorganiza os valores atribuídos às variáveis n1, n2 e n3 de modo a 
imprimir estes valores em ordem crescente. O algoritmo funciona da seguinte maneira:
1) Verifica se o valor atribuído a n2 é maior ou igual que n3, se sim, ele faz a 
troca dos valores atribuídos a estas variáveis usando uma variável auxiliar.
2) Verifica se n1 é maior ou igual a n2, se sim, ele faz a 
troca dos valores atribuídos a estas variáveis usando uma variável auxiliar e logo 
em seguida (dentro do bloco condicional), verifica se n2 é maior ou igual a n3 e 
se este for o caso, faz a troca dos valores atribuídos a estas variáveis também 
(usando a variável auxiliar).
Este algoritmo garante que ao final do programa n1 sempre estará com o menor valor,
n2 sempre estará com o valor intermediário e n3 sempre estará com o maior valor.
*/
#include <stdio.h>

int main () {
  int n1, n2, n3, aux;

  if (n2>=n3) 
  {
    aux = n2;
    n2 = n3;
    n3 = aux;
  }
  if (n1>=n2) 
  {
    aux = n1;
    n1 = n2;
    n2 = aux;
    if (n2>=n3) 
    {
      aux = n2;
      n2 = n3;
      n3 = aux;
    } 
  }
  printf ("%d %d %d\n", n1, n2, n3);
  return (0);
}