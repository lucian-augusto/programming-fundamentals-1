#include <stdlib.h>
#include <stdio.h>

#define BUFFER 1024

int main() {
    FILE *a;
    char str[BUFFER];

    a = fopen("file.txt", "r");
    int i;
    for (i = 0; i < 3; i++) {
      if (fgets(str, BUFFER, a)) {
        printf("%s", str);
      }
    }

    fclose(a);

    return 0;
}
