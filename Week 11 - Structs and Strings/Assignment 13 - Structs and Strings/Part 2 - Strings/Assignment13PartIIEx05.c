#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void abbreviateName(char *name, char *abbr);
void captureName(char *s);

int main(void) {
    char name[BUFFER_SIZE];
    char abbr[BUFFER_SIZE] = "";

    captureName(name);
    abbreviateName(name, abbr);
    
    printf("Nome Completo: %s\nAbreviação: %s\n", name, abbr);
    
    return 0;
}

void abbreviateName(char *name, char *abbr) {
    char nameCopy[BUFFER_SIZE];
    char sep[2] = " ";
    char *token;

    strcpy(nameCopy, name);

    token = strtok(nameCopy, sep);
    while (token != NULL) {
        if (strlen(token) <= 2) {
            strcat(abbr, token);
            strcat(abbr, " ");
        } else {
            strncat(abbr, &token[0], 1);
            strcat(abbr, ". ");
        }
        token = strtok(NULL, sep);
    }
}

void captureName(char *n) {
    printf("Por favor, insira o seu nome: ");
    fgets(n, BUFFER_SIZE, stdin);
    n[strcspn(n, "\n")] = 0;
}
