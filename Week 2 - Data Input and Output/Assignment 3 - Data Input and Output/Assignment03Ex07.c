#include  <stdio.h>

// Este código apresenta um erro de execução, referente a 
// indicação do tipo da variável dentro do comando printf 
// que exibe o valor da variável inserida. No caso, a 
// variável aux é uma variável do tipo int, porém no 
// printf, estamos usando um marcador de tipo referente 
// ao tipo float ("%f"), resultando num valor exibido não 
// condizente com o valor lido (o repl.it inclusive, 
// apresenta um warning ao compilar o programa referente 
// a isso). Para resolver e corrigir este problema basta // alterar o indicador de tipo de variável para "%d" que 
// é referente a variáveis do tipo int.

int  main(){
  int  aux;
  
  printf("Digite  um  numero  inteiro: ");
  scanf("%d", &aux);
  // printf("%f", aux); // linha errada - indicador de tipo de variável não condizente com o tipo da variável

  printf("%d", aux); // correção!
  return  0;
}