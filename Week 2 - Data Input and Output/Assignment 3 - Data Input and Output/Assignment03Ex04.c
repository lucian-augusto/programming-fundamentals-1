#include <stdio.h>

int main(void) {
  char charVariable;
  int intVariable;
  float floatVariable;

  // Para mudar a ordem de entrada das variáveis, é necessário mudar não somente o 
  // nome da variável em questão dentro do comando "scanf", mas também, precisamos 
  // mudar a indicação do formato da variável (no caso, de '%c' do tipo char para 
  // '%d' do tipo int). 
  // Outra coisa que devemos ter cuidado, é que o comando 
  // "scanf" armazena um buffer do teclado, isto é, ele armazena as entradas após  
  // o valor inserido, incluindo a tecla "enter" (necessária para a captura do 
  // valor inserido) que insere um caractere de quebra de linha ("\n") no buffer. 
  // Este caractere é capturado pelo próximo "scanf" resultando em um erro de 
  // execução do programa. Vale notar que no exercício anterior, este problema não
  // era visível, pois a ordem dos tipos de variáveis que estávamos usando, afinal
  // estávamos capturando primeiro um char e depois um int. Neste caso, mesmo com 
  // o buffer de teclado, uma variável do tipo int só aceita números inteiros,
  // com isso, o "\n" armazenado no buffer não será aceito pela variável, evitando 
  // automaticamente o problema que estamos tendo neste exercício.
  // Entretanto, neste exercício, como estamos capturando um char, o charactere
  // de quebra de linha acaba sendo capturado. Para resolver este problema,
  // podemos fazer uma limpeza do buffer do teclado. Uma maneira de fazer isso é
  // "capturar" caractere de quebra de linha ("\n")
  // utilizando o comando "getchar()". Outra solução, é informar ao comando scanf
  // referente à captura do caractere para ignorar o primeiro caractere do buffer
  // utilizando um espaço antes do indicador da variável " %c".

  printf("Por favor, entre um número inteiro (sem ponto flutuante): ");
  scanf("%d", &intVariable);

  getchar(); // Solução 1

  printf("Por favor, entre um caractere: ");
  scanf("%c", &charVariable); // Solução 1
  // scanf(" %c", &charVariable); // Solução 2

  printf("Por favor, entre um número inteiro (ponto flutuante é váldio): ");
  scanf("%f", &floatVariable);

  printf("Os valores das variáveis que você entrou são:\n");
  printf("'int': %d;\n'char': %c;\n'float': %f.\n", intVariable, charVariable, floatVariable);
  return 0;
}