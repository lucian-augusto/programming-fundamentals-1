#include <stdio.h>
#define MIN 1
#define MAX 20

int main(void) {
  int i;
  long iterator;
  long lcm = 0;

  iterator = MAX;
  if (iterator % 2 != 0) { // Apenas valores pares podem ser divididos por todos os números entre MIN e MAX já que o número 2 está entre eles.
    iterator++;
  }

  while (!lcm) {
    for (i = MIN; i <= MAX; i++) {
      if (iterator % i != 0) {
        lcm = 0;
        break;
      }
      lcm = iterator;
    } 
    iterator +=2;   
  }

  printf("%ld", lcm);
  return 0;
}