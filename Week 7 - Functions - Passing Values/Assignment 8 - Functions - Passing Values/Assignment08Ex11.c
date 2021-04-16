#include <stdio.h>

int contaDigitos(int n, int d);
int ehPermutacao(int n1, int n2);
void ehPermutacaoTest(int n1, int n2);

int contaDigitos(int n, int d) {
  int repetCounter = 0;

  while (n > 0) {
    if (n % 10 == d) {
      repetCounter++;
    }
    n /= 10;
  }
  return repetCounter;
}

int ehPermutacao(int n1, int n2) {
  int isPermutation = 1;
  int numberUnderAnalysis = n1;

  while (numberUnderAnalysis > 0 && isPermutation) {
    if (contaDigitos(n1, numberUnderAnalysis % 10) != contaDigitos(n2, numberUnderAnalysis % 10)) {
      isPermutation = 0;
    }
    numberUnderAnalysis /= 10;
  }
  return isPermutation;
}

void ehPermutacaoTest(int n1, int n2) {
  printf("%d\n", ehPermutacao(n1, n2));
}

int main(void) {
  ehPermutacaoTest(5412434, 4321445);
  ehPermutacaoTest(5412434, 4312455);
  ehPermutacaoTest(123, 231);
  ehPermutacaoTest(123, 234);
  ehPermutacaoTest(123, 121);
  ehPermutacaoTest(121, 212);
  ehPermutacaoTest(121, 211);
  ehPermutacaoTest(777, 7);
  
  return 0;
}