#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 1024

int main(void) {
  FILE *a;
  int num[15];
  char *token;
  char str[BUFFER];
  a = fopen("File.csv", "r");

  int i;
  int numIndex = 0;
  for (i = 0; i < 3; i++) {
    if (fgets(str, BUFFER, a)) {
      token = strtok(str, ",");
      while (token != NULL) {
        num[numIndex] = atoi(token);
        numIndex++;
        token = strtok(NULL, ",");
      }
    }
  }

  fclose(a);

  for (i = 0; i < 15; i++) {
    printf("valor[%d] = %d\n", i, num[i]);
  }

  return 0;
}
