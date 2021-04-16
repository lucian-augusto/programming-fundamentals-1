#include <stdio.h>

int main(void) {
  char letters[4] = {'A', 'B', 'C', 'D'};
  int lettersLength = sizeof(letters)/sizeof(letters[0]);
  printf("Imprimindo o código ASCII das letras 'A' até 'D':\n");

  for (int i = 0; i < lettersLength; i++) {
    printf("'%c' = %d\n", letters[i], letters[i]);
  }
  return 0;
}