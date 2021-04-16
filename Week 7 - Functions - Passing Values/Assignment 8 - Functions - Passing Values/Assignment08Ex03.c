#include <stdio.h>

int testaTipoChar(char c) {
  int asciiValue = c;

  if (asciiValue >= 65 && asciiValue <= 90) {
    return 1;
  } 
  if (asciiValue >= 97 && asciiValue <= 122) {
    return 2;
  }
  if (asciiValue >= 48 && asciiValue <= 57) {
    return 3;
  }
  return 0;
}

int main(void) {
  printf("%c -> %d\n", 'a', testaTipoChar('a'));
  printf("%c -> %d\n", 'l', testaTipoChar('l'));
  printf("%c -> %d\n", 'z', testaTipoChar('z'));

  printf("%c -> %d\n", 'A', testaTipoChar('A'));
  printf("%c -> %d\n", 'L', testaTipoChar('L'));
  printf("%c -> %d\n", 'Z', testaTipoChar('Z'));

  printf("%c -> %d\n", '0', testaTipoChar('0'));
  printf("%c -> %d\n", '7', testaTipoChar('7'));
  printf("%c -> %d\n", '9', testaTipoChar('9'));

  printf("%c -> %d\n", ' ', testaTipoChar(' '));
  printf("%c -> %d\n", '\n', testaTipoChar('\n'));
  printf("%c -> %d\n", '~', testaTipoChar('~'));
  return 0;
}