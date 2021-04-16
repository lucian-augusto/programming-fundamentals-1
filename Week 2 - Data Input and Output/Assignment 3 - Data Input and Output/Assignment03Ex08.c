#include  <stdio.h>

int  main() {
  char  aux;

  printf("Digite  um  caracter: ");
  scanf("%c", &aux);
  
  printf("%d", aux);
  
  return  0;
}

// O número exibido pelo programa é o código ASCII do 
// caractere digitado pelo usuário. Ele possui um 
// significado próprio (valor que identifica o caractere 
// dentro da tabela ASCII de caracteres), portanto, não é 
// um erro (a não ser que o objetivo do programa NÃO seja 
// exibir o código ASCII do caractere inserido pelo 
// usuário).