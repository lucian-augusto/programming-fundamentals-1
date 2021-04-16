#include <stdio.h>
#include <ctype.h>

int main(void) {
  char letters[4] = {'A', 'B', 'C', 'D'};
  int lettersLength = sizeof(letters)/sizeof(letters[0]);
  printf("Convertendo as letras maiúsculas '%c', '%c', '%c' e '%c':\n", letters[0], letters[1], letters[2], letters[3]);

  for (int i = 0; i < lettersLength; i++) {
    char convertedLetter = tolower(letters[i]);
    printf("'%c' -> '%c'\n", letters[i], convertedLetter);
  }
  return 0;
}