#include <stdlib.h>
#include <stdio.h>

#define BUFFER 1024

int main() {
    FILE *a;
    char str[BUFFER];

    a = fopen("Arquivo.txt", "r");

    if (fgets(str, BUFFER, a)) {
        puts(str);
    }

    printf("%s", str);

    return 0;
}
